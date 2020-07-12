#include "musicplayer.h"
#include "ui_musicplayer.h"

musicPlayer::musicPlayer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::musicPlayer)
{
    ui->setupUi(this);
    //快藏起来
    ui->buttonLast->setVisible(false);
    ui->buttonNext->setVisible(false);
    ui->buttonPause->setVisible(false);
    ui->buttonhelp->setVisible(false);
    ui->buttonVolum->setVisible(false);
    ui->buttonadd->setVisible(false);
    ui->buttonback->setVisible(false);
    ui->buttonreload->setVisible(false);
    ui->buttonMode->setVisible(false);
    ui->labVolum->setVisible(false);
    ui->labhelp->setVisible(false);
    ui->positiSlider->setVisible(false);
    ui->volumSlider->setVisible(false);
    ui->musicList->horizontalHeader()->setVisible(false);
    //给按钮加手  这手真丑
    ui->buttonInit->setCursor(QCursor(Qt::PointingHandCursor));
    ui->buttonadd->setCursor(QCursor(Qt::PointingHandCursor));
    ui->buttonreload->setCursor(QCursor(Qt::PointingHandCursor));
    ui->buttonback->setCursor(QCursor(Qt::PointingHandCursor));
    ui->buttonhelp->setCursor(QCursor(Qt::PointingHandCursor));
    ui->buttonVolum->setCursor(QCursor(Qt::PointingHandCursor));
    //设置选取一行   感觉这波可以但没必要
    ui->musicList->setSelectionBehavior(QAbstractItemView::SelectRows);

    player=new QMediaPlayer;
    playlist=new QMediaPlaylist;
    //先捯饬一波界面
    QPalette palette(this->palette());
    palette.setColor(QPalette::Background, Qt::white);
    this->setPalette(palette);
    this->setFixedSize(470,580);
    //音乐列表不可修改  锁了
    ui->musicList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    connect(ui->buttonInit,&QPushButton::clicked,this,&musicPlayer::init);               //链接初始化按钮
    connect(ui->buttonPause,&QPushButton::clicked,this,&musicPlayer::slotforbuttonpause);//链接播放|暂停按钮
    connect(ui->buttonLast,&QPushButton::clicked,this,&musicPlayer::slotforbuttonlast);  //链接上一首 按钮
    connect(ui->buttonNext,&QPushButton::clicked,this,&musicPlayer::slotforbuttonnext);  //链接下一首 按钮
    connect(ui->volumSlider,&QSlider::valueChanged,this,&musicPlayer::slotforvolum);     //链接音量滑块
    //链接说明按钮
    connect(ui->buttonhelp,&QPushButton::clicked,[=](){
        if(ui->labhelp->isVisible())
            ui->labhelp->setVisible(false);
        else
            ui->labhelp->setVisible(true);
    });
    connect(ui->buttonVolum,&QPushButton::clicked,this,&musicPlayer::slotforbuttonVolum);//音量按钮
    //同步音乐进度滑块和音乐进度
    connect(player,&QMediaPlayer::positionChanged,[=](qint64 po){
       ui->positiSlider->setValue(po);
    });
    //同步音乐时长和音乐进度滑块最大值
    connect(player,&QMediaPlayer::durationChanged,[=](qint64 dura){
        ui->positiSlider->setRange(0,dura);
        ui->positiSlider->setEnabled(dura>0);                     //有音乐时滑块才可用
        ui->positiSlider->setPageStep(dura/10);                   //设置滑块间隔为总时长的1/10
    });
    //手动拖动 音乐进度滑块 时，同步音乐播放进度
    connect(ui->positiSlider,&QSlider::valueChanged,[=](int po){
        if(qAbs(player->position()-po)>101)//避免 音乐进度改变 和 滑块值改变 导致互相调用
            player->setPosition(po);
    });
    //换歌时，UI音乐列表中 高亮位置 的切换
    connect(player,&QMediaPlayer::mediaStatusChanged,[=](QMediaPlayer::MediaStatus statu){
        if(isreloading==false&&playlist->currentIndex()!=lastmusicindex)//避免重载音乐列表时触发此信号造成的影响
        {
            ui->musicList->item(lastmusicindex,0)->setBackground(QBrush(QColor(155,165,200,0)));
            lastmusicindex=playlist->currentIndex();
            showcurrentmusic();
            ui->musicList->item(selectedrow,0)->setSelected(false);
        }
    });
    //链接 模式按钮   改变音乐列表播放模式
    connect(ui->buttonMode,&QPushButton::clicked,[=](){
           static int markformode=1;
           if(markformode%3==0)
           {
               playlist->setPlaybackMode(QMediaPlaylist::Loop);
               ui->buttonMode->setIcon(QIcon(":./image/loop.png"));
           }
           else if(markformode%3==1)
           {
               playlist->setPlaybackMode(QMediaPlaylist::Random);
               ui->buttonMode->setIcon(QIcon(":./image/random.png"));
           }
           else if(markformode%3==2)
           {
               playlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
               ui->buttonMode->setIcon(QIcon(":./image/oneloop.png"));
           }
           markformode++;
    });
    //双击播放选中的音乐
    connect(ui->musicList,&QTableWidget::cellDoubleClicked,[=](int row, int column){
        if(playlist->currentIndex()!=row||(!isplaying))
        {
            selectedrow=row;
            playlist->setCurrentIndex(row);
            if(!isplaying)
                slotforbuttonpause();
            showcurrentmusic();
        }
    });
}
//初始化按钮 槽函数
void musicPlayer::init()
{
    musicPath=new QString;
    //弹窗选取音乐文件夹
    *musicPath=QFileDialog::getExistingDirectory(this,"你的音乐放哪了",QStandardPaths::standardLocations(QStandardPaths::MusicLocation).value(0, QDir::homePath()),QFileDialog::ShowDirsOnly);
    if(!musicPath->isEmpty())
    {
            ui->buttonLast->setVisible(true);
            ui->buttonNext->setVisible(true);
            ui->buttonPause->setVisible(true);
            ui->buttonhelp->setVisible(true);
            ui->buttonVolum->setVisible(true);
            ui->buttonMode->setVisible(true);
            ui->positiSlider->setVisible(true);
            ui->buttonInit->setGeometry(440,40,21,101);
            ui->buttonVolum->move(437,160);
            ui->labhand->setVisible(false);
            ui->musicList->setStyleSheet("selection-background-color:rgba(255, 230, 169,255);background-color:rgba(155,165,200,0);");
            ui->buttonInit->setStyleSheet("background-color:rgba(100,165,200,150)");
            //初始化按钮变更作用  变为改变音乐列表按钮
            disconnect(ui->buttonInit,&QPushButton::clicked,this,&musicPlayer::init);
            connect(ui->buttonInit,&QPushButton::clicked,[=](){
                ui->buttonInit->setVisible(false);
                ui->buttonadd->setVisible(true);
                ui->buttonreload->setVisible(true);
                ui->buttonback->setVisible(true);
            });
            //链接 重载音乐列表按钮
            connect(ui->buttonreload,&QPushButton::clicked,[=](){
                reloeadmusiclist();
            });
            //链接 添加音乐按钮
            connect(ui->buttonadd,&QPushButton::clicked,[=](){
                addmusiclist();
            });
            //链接返回按钮
            connect(ui->buttonback,&QPushButton::clicked,[=](){
                ui->buttonInit->setVisible(true);
                ui->buttonadd->setVisible(false);
                ui->buttonreload->setVisible(false);
                ui->buttonback->setVisible(false);
            });
        //获取音乐名称列表
        filelist=getFileName(*musicPath);
        //将文件中的音乐添加到ui的音乐列表，以及播放列表中
        for(int i=0;i<filelist.size();++i)
        {
            addItem(filelist.at(i));
            playlist->addMedia(QUrl::fromLocalFile(*musicPath+"\\"+filelist.at(i)));
        }
        playlist->setCurrentIndex(0);
        //初始播放模式为循环
        playlist->setPlaybackMode(QMediaPlaylist::Loop);
        //载入播放列表
        player->setPlaylist(playlist);
        //初始音量
        player->setVolume(50);
        //若所选文件夹无音乐 设置按钮不可用
        if(playlist->isEmpty())
        {
            ui->buttonPause->setEnabled(false);
            ui->buttonLast->setEnabled(false);
            ui->buttonNext->setEnabled(false);
        }
        //再捯饬一波界面
        this->setAutoFillBackground(true);
        QPalette palette;
        QPixmap pixmap(":./image/windowback.jpeg");
        palette.setBrush(QPalette::Window, QBrush(pixmap));
        this->setPalette(palette);
    }
}
//获取音乐名称
QStringList musicPlayer::getFileName(const QString& path)
{
    QDir dir(path);
    QStringList nameFilters;
    nameFilters<<"*.mp3"<<"*wav";//支持mp3格式和wav格式
    QStringList files=dir.entryList(nameFilters,QDir::Files|QDir::Readable,QDir::Name);
    return files;
}
//将音乐名称载入UI中音乐列表
void musicPlayer::addItem(QString name)
{
    int count=ui->musicList->rowCount();
    ui->musicList->setRowCount(count+1);
    QTableWidgetItem *itemName= new QTableWidgetItem(name);
    ui->musicList->setItem(count,0,itemName);
}
//播放|暂停
void musicPlayer::slotforbuttonpause()
{
    if(!isplaying)
    {
        ui->buttonPause->setIcon(QIcon(":/image/pause.ico"));
        ui->buttonPause->setStyleSheet("background-color: rgba(187, 120, 194,125)");
        isplaying=true;
        player->setVolume(ui->volumSlider->value());
        player->play();
        showcurrentmusic();
    }
    else
    {
        ui->buttonPause->setIcon(QIcon(":/image/star.ico"));
        ui->buttonPause->setStyleSheet("background-color: rgba(187, 184, 255,125)");
        isplaying=false;
        player->pause();
    }
}
//下一首
void musicPlayer::slotforbuttonnext()
{
    //处理 已经播放到末尾音乐 情况
    if(playlist->currentIndex()==(filelist.end()-filelist.begin()-1))
    {
        playlist->setCurrentIndex(0);
    }
    else
    {
        playlist->next();
    }
}
//上一首
void musicPlayer::slotforbuttonlast()
{
    //处理 已经播放到首个音乐 情况
    if(playlist->currentIndex()==0)
    {
        playlist->setCurrentIndex(filelist.end()-filelist.begin()-1);
    }
    else
    {
        playlist->previous();
    }
}
//显示正在播放的音乐
void musicPlayer::showcurrentmusic()
{
    this->setWindowTitle(filelist.at(playlist->currentIndex()));
    ui->musicList->item(playlist->currentIndex(),0)->setBackground(QBrush(QColor(100,150,164)));
}
//拖动音量滑块时的响应 改变播放音量 改变显示的音量值
void musicPlayer::slotforvolum()
{
    ui->labVolum->setNum(ui->volumSlider->value());
    player->setVolume(ui->volumSlider->value());
}
//点击音量按钮 呼出|关闭音量滑块
void musicPlayer::slotforbuttonVolum()
{
    if(ui->volumSlider->isVisible()){
        ui->buttonVolum->move(437,160);
        ui->volumSlider->setVisible(false);
        ui->labVolum->setVisible(false);
    }
    else
    {
        ui->buttonVolum->move(437,492);
        ui->volumSlider->setVisible(true);
        ui->labVolum->setVisible(true);
    }
}
//重载音乐列表
void musicPlayer::reloeadmusiclist()
{
    if(!ui->buttonPause->isEnabled())
    {
        ui->buttonPause->setEnabled(true);
        ui->buttonLast->setEnabled(true);
        ui->buttonNext->setEnabled(true);
    }
    //获取音乐文件夹路径
    musicPath=new QString;
    *musicPath=QFileDialog::getExistingDirectory(this,"你的音乐放哪了",QStandardPaths::standardLocations(QStandardPaths::MusicLocation).value(0, QDir::homePath()),QFileDialog::ShowDirsOnly);
    if(!musicPath->isEmpty())
    {
        isreloading=true;
        //重载列表时暂停播放
        if(isplaying)
        {
            slotforbuttonpause();
        }
        //重置上一首音乐的索引标记
        lastmusicindex=0;
        //清空播放列表
        playlist->clear();
        //获取音乐文件夹内所有音乐文件名称
        filelist=getFileName(*musicPath);
        qDebug()<<"All music :"<<filelist;
        //清空UI音乐列表
        ui->musicList->clearContents();
        //重置音乐列表行数
        ui->musicList->setRowCount(0);
        //将文件中的音乐添加到ui的音乐列表中
        for(int i=0;i<filelist.size();++i)
        {
            addItem(filelist.at(i));
            playlist->addMedia(QUrl::fromLocalFile(*musicPath+"\\"+filelist.at(i)));
        }
        playlist->setCurrentIndex(0);
        //若所选文件夹无音乐 设置按钮不可用
        if(playlist->isEmpty())
        {
            ui->buttonPause->setEnabled(false);
            ui->buttonLast->setEnabled(false);
            ui->buttonNext->setEnabled(false);
        }
        isreloading=false;
    }
}
//添加音乐
void musicPlayer::addmusiclist()
{
    if(!ui->buttonPause->isEnabled())
    {
        ui->buttonPause->setEnabled(true);
        ui->buttonLast->setEnabled(true);
        ui->buttonNext->setEnabled(true);
    }
    //获取音乐文件夹路径
    musicPath=new QString;
    *musicPath=QFileDialog::getExistingDirectory(this,"你的音乐放哪了",QStandardPaths::standardLocations(QStandardPaths::MusicLocation).value(0, QDir::homePath()),QFileDialog::ShowDirsOnly);
    if(!musicPath->isEmpty())
    {
        int markfileindex=filelist.size();
        //音乐名称列表中添加新的音乐名称
        filelist+=getFileName(*musicPath);
        qDebug()<<"All music :"<<filelist;
        //UI音乐列表、播放列表添加新的音乐
        if(filelist.size()!=markfileindex+1)
        {
            for(int i=markfileindex;i!=filelist.size();++i)
            {
                addItem(filelist.at(i));
                playlist->addMedia(QUrl::fromLocalFile(*musicPath+"\\"+filelist.at(i)));
            }
        }
    }
}
//键盘事件，设置快捷键
void musicPlayer::keyPressEvent(QKeyEvent *event)
{
    //需要ctrl
    if(event->modifiers() ==Qt::ControlModifier)
    {
        //ctrl+W 大声点儿
        if(event->key() == Qt::Key_W)
        {
            if(ui->volumSlider->value()<90)
                ui->volumSlider->setValue(ui->volumSlider->value()+10);
            else
                ui->volumSlider->setValue(100);
        }
        //ctrl+S 小声点儿
        else if(event->key() == Qt::Key_S)
        {
            if(ui->volumSlider->value()>10)
                ui->volumSlider->setValue(ui->volumSlider->value()-10);
            else
                ui->volumSlider->setValue(0);
        }
        //ctrl+Q 上一首
        else if(event->key()==Qt::Key_Q)
        {
            if(ui->buttonLast->isVisible()&&ui->buttonLast->isEnabled())
                slotforbuttonlast();
        }
        //ctrl+E 下一首
        else if(event->key()==Qt::Key_E)
        {
            if(ui->buttonNext->isVisible()&&ui->buttonNext->isEnabled())
                slotforbuttonnext();
        }
        //ctrl+F 播放|暂停
        else if(event->key()==Qt::Key_F)
        {
            if(ui->buttonPause->isVisible()&&ui->buttonPause->isEnabled())
                slotforbuttonpause();
        }
        //ctrl+R 重载音乐列表
        else if(event->key()==Qt::Key_R)
        {
            if(ui->buttonhelp->isVisible())
                reloeadmusiclist();
        }
        //ctrl+C 添加音乐
        else if(event->key()==Qt::Key_C)
        {
            if(ui->buttonhelp->isVisible())
                addmusiclist();
        }
    }
    else QWidget::keyPressEvent(event);
}

musicPlayer::~musicPlayer()
{
    delete ui;
}

void musicPlayer::closeEvent(QCloseEvent *event)
{
    emit closed();
}

