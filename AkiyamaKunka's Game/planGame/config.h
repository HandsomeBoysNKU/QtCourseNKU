#ifndef CONFIG_H
#define CONFIG_H

//here you can set the configuration of the game
#define GAME_WID 512

#define GAME_LEN 768

#define GAME_TITEL "Love and Peace"
#define PLANE_ICON ":/image/飞机大战素材/hero.png"
#define PLANE_ICON1 ":/image/飞机大战素材/hero2.png"
#define PLANE_LIFE 500

#define MAP_LOCAT ":/image/飞机大战素材/img_bg_level_3.jpg"
#define MAP_LOCAT1 ":/image/飞机大战素材/img_bg_level_2.jpg"
#define MAP_LOCAT2 ":/image/飞机大战素材/img_bg_level_5.jpg"

#define BULLET_LOCAT ":/image/飞机大战素材/bullet_9.png"
#define BULLET_LOCAT1 ":/image/飞机大战素材/bullet_11.png"
#define BULLET_LOCAT2 ":/image/飞机大战素材/bullet_14.png"

#define BULLET_SPEED 3
#define BULLET_REFRESH_RATE 40 //the smaller, the faster

#define BULLET_REFRESH_RATE1 100




#define BULLET_NUM 10000
#define BULLET_INTERVAL 1

#define ENEMY_PATH  ":/image/飞机大战素材/img-plane_5.png"
#define ENEMY_PATH1 ":/image/飞机大战素材/img-plane_2.png"
#define ENEMY_PATH2 ":/image/飞机大战素材/img-plane_7.png"
#define ENEMY_SPEED 5
#define ENEMY_NUM   10000
#define ENEMY_INTERVAL  30

#define BOMB_PATH  ":/image/飞机大战素材/bomb-%1.png"
#define BOMB_NUM  20
#define BOMB_MAX  7      //the maximum index of bomb pictures
#define BOMB_INTERVAL 4

#define PLANE_WID 100
#define PLANE_LEN 100
#define PLANE_MOVE_SPEED 4
#define REFRESH_RATE 5
#define MAP_SPEED 2


#define Level_1_SCORE 400
#define Level_2_SCORE 1000
#define Level_1_PLANE_SCORE 800
#define Level_1_BULLET_SCORE 500
#define Level_2_BULLET_SCORE 1300


#endif // CONFIG_H


