//
// Created by 18237 on 2023/11/29.
//

#ifndef MXPROJECT_MATH_H
#define MXPROJECT_MATH_H
float Limit(float val, const float& min, const float& max){
    float result;
    if(val > min && val < max){
        result = val;
    }
    else if(val > max){
        result = max;
    }
    else if(val < min){
        result = min;
    }
    return result;
}
float LoopLimit(float val, const float& min, const float& max){
    float result;
    float period = max - min;
    if(val > min && val < max){
        result = val;
    }
    else if(val > max){
        result = val - (int((val - max)/period)+1)*period;
    }
    else if(val < min){
        result = val + (int((min-val)/period)+1)*period;
    }
    return result;
}
float DeadBand(float val, const float& min, const float& max){
    float result;
    if(val > min && val < max){
        result = 0;
    }
    else{
        result = val;
    }
    return result;
}
#endif //MXPROJECT_MATH_H
