#include"pid.h"

PID::PID(float kp, float ki, float kd, float i_max, float out_max): kp_(kp),ki_(ki),kd_(kd),i_max_(i_max),out_max_(out_max){
    err_ = 0;
    err_sum_ = 0;
    last_err_ = 0;
}

float PID::Calculate(float ref, float fdb){
    ref_=ref;
    fdb_=fdb;

    last_err_ = err_;
    err_ = ref_ - fdb_;
    err_sum_ = err_sum_ + err_;
    if(err_sum_>i_max_) err_sum_=i_max_;
    else if(err_sum_<-i_max_) err_sum_=-i_max_;

    p_out_ = kp_ * err_;
    i_out_ = ki_ * err_sum_;
    d_out_ = kd_ * (err_ - last_err_);
    output_ = p_out_ + i_out_ + d_out_;
    if(output_>out_max_) output_=out_max_;
    else if(output_<-out_max_) output_=-out_max_;

    return output_;
}