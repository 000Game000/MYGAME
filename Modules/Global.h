#ifndef GLOBAL_H
#define GLOBAL_H
#include<QList>
#include<QString>
#include"Mainwindow.h"
#include"Windows/BeginWindow.h"
#include"Windows/CreateLead.h"
#include<QDockWidget>
namespace MYGAME {
/*
 * 全局单例类
 * 1.包含现有专业
 * 2.包含职业
 * 3.包含窗口指针
 */
class Global
{
protected:
    QList<QString> majorList;                                       //专业列表
    QList<QString> careerList;                                      //职业列表
    MainWindow*mainWindow;
    BeginWindow*beginWindow;
    CreateLead*createLead;
public:
    Global();
    void initMajorList();                                           //初始化专业表列
    void initCareerList();                                          //初始化职业表列
    QList<QString> getMajorList();
    QList<QString> getCareerList();
    MainWindow *getMainWindow() const;
    void setMainWindow(MainWindow *newMainWindow);
    BeginWindow *getBeginWindow() const;
    void setBeginWindow(BeginWindow *newBeginWindow);
    CreateLead *getCreateLead() const;
    void setCreateLead(CreateLead *newCreateLead);
};
extern Global global;
}
#endif // GLOBAL_H
