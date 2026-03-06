#include<iostream>

class TimeSeries {
private:
    double* data;
    int size;
    
public:
    TimeSeries(int n) : size(n) {
        data = new double[n];
    }
    
    // operator[]：按索引访问
    double& operator[](int index) {
        return data[index];
    }
    
    // operator()：按时间戳访问（假设每10分钟一个点）
    double& operator()(int minutes) {
        int index = minutes / 10;
        if (index < 0 || index >= size) {
            throw std::out_of_range("Time out of range");
        }
        return data[index];
    }
    
    // operator()：带插值的版本
    double operator()(double minutes) const {
        int idx1 = static_cast<int>(minutes / 10);
        int idx2 = idx1 + 1;
        if (idx2 >= size) return data[idx1];
        
        double t1 = idx1 * 10;
        double t2 = idx2 * 10;
        // 线性插值
        return data[idx1] + (data[idx2] - data[idx1]) * 
               (minutes - t1) / (t2 - t1);
    }
};


int main() {
    TimeSeries ts(24);  // 4小时数据（10分钟间隔）
    
    ts[0] = 10.5;           // 设置第0个点
    ts(30) = 12.3;          // 设置30分钟的点（索引3）
    
    double v1 = ts[2];       // 索引访问
    double v2 = ts(25);      // 25分钟的点（会插值）
}