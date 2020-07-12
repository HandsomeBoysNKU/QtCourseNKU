#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QStringList>
#include <QDir>
#include <QDebug>
#include <QFileDialog>
#include <QStandardPaths>
#include <QTime>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QCloseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class musicPlayer; }
QT_END_NAMESPACE

class musicPlayer : public QMainWindow
{
    Q_OBJECT

public:
    musicPlayer(QWidget *parent = nullptr);
    ~musicPlayer();
    void closeEvent(QCloseEvent *event);

private:
    Ui::musicPlayer *ui;
    QMediaPlaylist *playlist;//播放列表
    QMediaPlayer *player;    //播放器
    QString *musicPath;      //音乐文件夹路径
    QStringList filelist;    //音乐名称列表
    int lastmusicindex=0;    //存放刚刚播放过的音乐的索引
    int selectedrow=0;
    bool isreloading=false;  //是否正在重载音乐列表
    bool isplaying=false;

signals:
    void closed();

private slots:
    void init();//初始化
    void keyPressEvent(QKeyEvent *event);
    QStringList getFileName(const QString& path);//获取音乐名称
    void addItem(QString name);                  //将文件中的音乐添加到ui的音乐列表中
    void showcurrentmusic();                     //显示正在播放的音乐
    void reloeadmusiclist();                     //重载音乐列表
    void addmusiclist();
public slots:
    void slotforbuttonpause();                   //播放/暂停
    void slotforbuttonnext();                    //下一首
    void slotforbuttonlast();                    //上一首
    void slotforbuttonVolum();                   //显示音量滑块
    void slotforvolum();                         //同步音量与音量滑块值
};
#endif // MUSICPLAYER_H
