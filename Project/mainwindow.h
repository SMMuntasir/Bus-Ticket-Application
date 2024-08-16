#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QMessageBox>
#include <QFileDialog>
#include <QPixmap>
#include <QApplication>
#include <QColorDialog>
#include <QColor>
#include <QDateTime>
#include<QCalendarWidget>
#include <QApplication>
#include <QVBoxLayout>
#include <QWidget>
#include <QSqlTableModel>
#include <QStandardItemModel>
#include <QPainter>
#include <QScreen>
#include <string>
#include <QGroupBox>
#include <QPushButton>
#include <QCheckBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onCheckBoxStateChanged(int);

    void on_Login_main_button_clicked();

    void on_Sign_up_main_button_clicked();

    void on_Submit_button_sign_up_clicked();

    void on_Login_button_clicked();

    void on_Sign_in_back_button_clicked();

    void on_Login_back_button_clicked();

    void on_Search_button_clicked();


    void on_pushButton_13_clicked();

    void on_Buy1_button_clicked();


    void on_A1_1_stateChanged(int arg1);

    void on_A2_1_stateChanged(int arg1);

    void on_B1_1_stateChanged(int arg1);

    void on_C1_1_stateChanged(int arg1);

    void on_D1_1_stateChanged(int arg1);

    void on_E1_1_stateChanged(int arg1);

    void on_F1_1_stateChanged(int arg1);

    void on_G1_1_stateChanged(int arg1);

    void on_H1_1_stateChanged(int arg1);

    void on_I1_1_stateChanged(int arg1);

    void on_B2_1_stateChanged(int arg1);

    void on_C2_1_stateChanged(int arg1);

    void on_D2_1_stateChanged(int arg1);

    void on_E2_1_stateChanged(int arg1);

    void on_F2_1_stateChanged(int arg1);

    void on_G2_1_stateChanged(int arg1);

    void on_H2_1_stateChanged(int arg1);

    void on_I2_1_stateChanged(int arg1);

    void on_A3_1_stateChanged(int arg1);

    void on_B3_1_stateChanged(int arg1);

    void on_C3_1_stateChanged(int arg1);

    void on_Buy_tickets_button_clicked();

    void on_My_tickets_button_clicked();

    void on_My_profile_back_button_clicked();

    void on_pushButton_17_clicked();

    void on_Log_out_button_clicked();

    void on_Change_photo_button_clicked();

    void on_D3_1_stateChanged(int arg1);

    void on_E3_1_stateChanged(int arg1);

    void on_F3_1_stateChanged(int arg1);

    void on_G3_1_stateChanged(int arg1);

    void on_H3_1_stateChanged(int arg1);

    void on_I3_1_stateChanged(int arg1);

    void on_A4_1_stateChanged(int arg1);

    void on_B4_1_stateChanged(int arg1);

    void on_C4_1_stateChanged(int arg1);

    void on_D4_1_stateChanged(int arg1);

    void on_E4_1_stateChanged(int arg1);

    void on_F4_1_stateChanged(int arg1);

    void on_G4_1_stateChanged(int arg1);

    void on_H4_1_stateChanged(int arg1);

    void on_I4_1_stateChanged(int arg1);

    void on_Edit_profile_button_clicked();


    void on_Update_button_clicked();

    void on_Admin_main_button_clicked();

    void on_Login_button_admin_clicked();

    void on_Admin_back_button_clicked();

    void on_Proceed_to_payment_button_clicked();


    void on_Seat_select_back_button_clicked();

    void on_Payment_page_back_button_clicked();

    void on_Apply_button_clicked();

    void on_Pay_button_clicked();

    void on_Profile_update_back_button_clicked();

    void on_hello_clicked();

    void on_My_ticket_back_button_clicked();

    void on_My_ticket_back_button_2_clicked();

    void on_Cancel_request_button_clicked();

    void on_Admin_next_button_2_clicked();

    void on_Admin_profile_back_button_clicked();

    void on_Admin_logout_button_clicked();

    void on_My_ticket_next_button_clicked();

    void on_Request_reject_button_clicked();

    void on_Request_accept_button_clicked();

    void on_Admin_add_button_clicked();

    void on_Admin_remove_button_clicked();

    void on_Change_photo_button_2_clicked();

    void on_Cancel_ticket_button_clicked();

    void on_Print_ticket_button_clicked();

    void on_Cancel_reject_button_clicked();

    void on_Admin_profile_back_button_2_clicked();

    void on_Admin_next_button_3_clicked();

    void on_Cancel_accept_button_clicked();

    void on_Download_ticket_button_clicked();

    ///void on_Cancel_ticket_seat_cursorPositionChanged(int arg1, int arg2);

    void on_Print_page_back_button_clicked();

private:
    Ui::MainWindow *ui;
    QString name,email,password,conf_password,mobile,imagepath,from,bus,to,type,birth,address,seat,coupon,seat_left,cancel,show_left,Class,date,newemail;
    int count,total,discount,seat_available,cancelnum;
    QSqlDatabase database;
};
#endif // MAINWINDOW_H
