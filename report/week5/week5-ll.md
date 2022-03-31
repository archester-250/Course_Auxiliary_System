## 完成课外活动类的基本设计

### 基础要求

学生可以输入课外活动信息，课外活动包括个人活动和集体活动；
- 个人活动可以包括：自习、锻炼、外出等，
- 集体活动可以包括：班会、小组作业、创新创业、聚餐等。

学生可以设定活动闹钟，闹钟可以是一次性的和周期性的，用于活动提醒。
系统可以检测个人活动、集体活动和课程的时间冲突，并给出提示。

### 实现设计

#### 初步类结构设计
```c++
class Time{
private:
    short year, month, day, hr, minute = 0, second = 0;
    short weekday = -1;
};

class Activity {
private:
    Time startTime;
    Time endTime;//活动起止时间
    char *address;
    Student students[32];//涉及到的学生
    bool clk;//闹钟标识，Todo
    char description[128];//活动内容描述
```

#### 初步类方法设计

- 设置活动起止时间时，由基础函数判断是否冲突
```c++
public:
    // Get 和 Set 方法
    const Time &getStartTime() const;

    void setStartTime(const Time &startTime);

    const Time &getEndTime() const;

    void setEndTime(const Time &endTime);

    char *getAddress() const;

    void setAddress(char *address);

    const Student *getStudents() const;

    bool isClk() const;

    void setClk(bool clk);

    const char *getDescription() const;
    
};
```

### 接下来的工作

完成与`Student`类、时间基础类等的设计
