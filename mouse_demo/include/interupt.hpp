#ifndef INTERUPT_HPP
#define INTERUPT_HPP

#include <iostream>
#include <string>
#include <memory>
#include "structs.hpp"
#include "Base_task.hpp"
#include "Search_task.hpp"
#include "Run_task.hpp" // 各タスクを追加
#include "Turn_task.hpp"
#include "Slalom_task.hpp"
#include "Log_task.hpp"
#include "Back_task.hpp"



void Interupt();
void calc_target(); //  目標値を計算する
void wall_ctl();   //  壁制御
void FB_ctl();    //  フィードバック制御
void calc_dist();   //  距離を計算
void calc_ang();    //  角度を計




#endif