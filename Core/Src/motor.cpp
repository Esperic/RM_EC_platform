//
// Created by 18237 on 2023/11/29.
//
#include "motor.h"

Motor::Motor(const Type& type, const float& ratio, const ControlMethod& method,
      const PID& ppid, const PID& spid){
    info_.type = type;
    info_.ratio = ratio;
    method_ = method;
    ppid_ = ppid;
    spid_ = spid;
}
void Motor::Reset(void){
    intensity_ = 0;
    mode_ = POWER_OFF;
    target_angle = 0;
    target_speed = 0;
}

void Motor::Handle(void){
    switch type{
        case M3508:
            spid.out_max_ = 16384;
            break;
        case M2006:
            spid.out_max_ = 10000;
            break;
        case GM6020:
            spid.out_max_ = 30000;
            break;
    }
    if(mode_ == WORKING){
        if(method_ == POSITION_SPEED){
            target_speed_ =ppid_.Calculate(target_angle_,angle);
            intensity_ = spid_.Calculate(target_speed_,rotate_speed)
        }else if(method_ == SPEED){
            target_angle_ = angle;
            intensity_ = spid_.Calculate(target_speed_,rotate_speed);
        }
    }else if(mode_ == STOP){
        target_angle_ = 0;
        target_speed_ = 0;
        intensity_ = spid_.Calculate(target_speed_,rotate_speed);

    }else if(mode_ == POWER_OFF){
        intensity_ = 0;
    }
    if(ratio < 0) intensity_ = -intensity_;
}

void Motor::SetAngle(const float& target_angle){
    target_angle_ = target_angle;
}

void Motor::SetSpeed(const float& target_speed){
    target_speed_ = target_speed;
}