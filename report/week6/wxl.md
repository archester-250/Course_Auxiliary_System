# 第六周总结
## 王祥龙
### 本周完成内容
✨简化代码，结构优化，新建login.h文件实现登录功能；
✨完成添加课程的功能，增加getter和setter，将赋值运算符重载
```c++
	char * getName();
    void setName(char * name);
    int getTime();
    void setTime(int time);
    char * getAddress();
    void setAddress(char * address);
    char ** getDocuments();
    void setDocuments(char ** documents);
    char * getCurrent();
    void setCurrent(char * current);
    char ** getFinished();
    void setFinished(char ** finished);
    char ** getUnfinished();
    void setUnfinished(char ** unfinished);
    int getExtime();
    void setExtime(int extime);
    char * getExaddress();
    void setExaddress(char * exaddress);
    void operator=(course& c);
```
(course.h)
```c++
void addCourse(course * c[], int & size, course newc);
```
(student.h)
### 下周计划
📝继续完成course功能实现
