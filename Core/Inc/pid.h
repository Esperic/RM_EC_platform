#ifndef __PID_H
#define __PID_H


class PID {
public:
    PID(float kp, float ki, float kd, float i_max, float out_max);
    float Calculate(float ref, float fdb);
public:
    float kp_, ki_, kd_;
    float i_max_, out_max_;
    float output_;
protected:
    float ref_, fdb_;
    float err_, err_sum_, last_err_;
    float p_out_, i_out_, d_out_;
};



#endif /* __PID_H */
