#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCheckBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    seat_left="";
    count=discount=0;
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    /*QPixmap picture(":/image/E:/Background/IMG_20231112_002332.jpg");
    ui->label_20->setPixmap(picture.scaled(800,500,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    QPixmap picture1(":/image/E:/Background/IMG_20231112_002318.jpg");
    ui->label_21->setPixmap(picture1.scaled(800,500,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));*/
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("D:/Local Disk H/QT/Project/project/peoject/bus.db");
    database.open();
    qDebug() <<database.isOpen();
    ui->From_combobox->addItem("Dhaka");ui->To_combobox->addItem("Dhaka");
    ui->From_combobox->addItem("Khulna");ui->To_combobox->addItem("Khulna");
    ui->From_combobox->addItem("Gazipur");ui->To_combobox->addItem("Gazipur");
    ui->From_combobox->addItem("Rangamati");ui->To_combobox->addItem("Rangamati");
    ui->From_combobox->addItem("Munshiganj");ui->To_combobox->addItem("Munshiganj");
    ui->From_combobox->addItem("Noakhali");ui->To_combobox->addItem("Noakhali");
    ui->From_combobox->addItem("Chattogram");ui->To_combobox->addItem("Chattogram");
    ui->From_combobox->addItem("Kishoreganj");ui->To_combobox->addItem("Kishoreganj");
    ui->From_combobox->addItem("Pabna");ui->To_combobox->addItem("Pabna");
    ui->From_combobox->addItem("Comilla");ui->To_combobox->addItem("Comilla");
    ui->From_combobox->addItem("Gopalganj");ui->To_combobox->addItem("Gopalganj");
    ui->From_combobox->addItem("Jashore");ui->To_combobox->addItem("Jashore");
    ui->From_combobox->addItem("Faridpur");ui->To_combobox->addItem("Faridpur");
    ui->From_combobox->addItem("Dinajpur");ui->To_combobox->addItem("Dinajpur");
    ui->From_combobox->addItem("Rangpur");ui->To_combobox->addItem("Rangpur");
    ui->From_combobox->addItem("Feni");ui->To_combobox->addItem("Feni");
    ui->From_combobox->addItem("Cox's Bazar");ui->To_combobox->addItem("Cox's Bazar");
    ui->From_combobox->addItem("Khulna");ui->To_combobox->addItem("Khulna");
    ui->From_combobox->addItem("Bogura");ui->To_combobox->addItem("Bogura");
    ui->Class_combobox->addItem("Economy AC");ui->Class_combobox->addItem("Sleeper AC");
    ui->Class_combobox->addItem("Hino 1JPluss AC");ui->Class_combobox->addItem("Hino 1JPluss Non AC");
    ui->Class_combobox->addItem("Hyundai AC");
    ui->Date_combobox->addItem("25 November 2023"); ui->Date_combobox->addItem("26 November 2023");
    ui->Date_combobox->addItem("27 November 2023"); ui->Date_combobox->addItem("28 November 2023");
    ui->Date_combobox->addItem("29 November 2023"); ui->Date_combobox->addItem("30 November 2023");
}
MainWindow::~MainWindow()
{
    delete ui;
    database.close();
}
void MainWindow::onCheckBoxStateChanged(int)
{
}

void MainWindow::on_Login_main_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_Sign_up_main_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_Submit_button_sign_up_clicked()
{
    name = ui->Name_input_sign_up->text();
    email=ui->Email_input_sign_up->text();
    mobile=ui->Mobile_input_sign_up->text();
    password=ui->Password_input_sign_up->text();
    conf_password=ui->Conf_pass_input_sign_up->text();
    imagepath="E:/project pic/nopic.jpg";

    if(name=="")
        QMessageBox::warning(this,"Sign up","Name field can't be empty");
    else if(email=="")
        QMessageBox::warning(this,"Sign up","Email field can't be empty");
    else if(mobile=="")
        QMessageBox::warning(this,"Sign up","Mobile field can't be empty");
    else if(password=="")
        QMessageBox::warning(this,"Sign up","Password field can't be empty");
    else if(conf_password=="")
        QMessageBox::warning(this,"Sign up","Password field can't be empty");
    else if(password!=conf_password)
        QMessageBox::warning(this,"Sign up","Password & Confirm password doesn't match");
    else {
        QSqlQuery query1;
        query1.exec("SELECT * FROM user WHERE email = '"+email+"' ");
        if(query1.next()) {
            QMessageBox::about(this,"Sign up","This email is already taken");
            ui->Email_input_sign_up->clear();
            ui->Email_input_sign_up->setText(email);
        }
        else {
            query1.exec("INSERT INTO user (name,email,password,mobile,image) VALUES ('"+name+"','"+email+"','"+password+"','"+mobile+"','"+imagepath+"')");
            ui->stackedWidget->setCurrentIndex(2);
            ui->Name_input_sign_up->clear();
            ui->Email_input_sign_up->clear();
            ui->Mobile_input_sign_up->clear();
            ui->Password_input_sign_up->clear();
            ui->Conf_pass_input_sign_up->clear();
            QMessageBox::information(this,"Sign up","Successfully signed up");
        }
    }
}



void MainWindow::on_Login_button_clicked()
{
    email=ui->Email_input_login->text();
    password=ui->Password_input_login->text();
    if(email=="")
        QMessageBox::warning(this,"Login","Email field can't be empty");
    else if(password=="")
        QMessageBox::warning(this,"Login","Password field can't be empty");
    else {
    QSqlQuery query1;
    query1.exec("SELECT * FROM user WHERE email = '"+email+"' AND password='"+password+"' ");

    if(query1.next()) {
        QMessageBox::information(this,"Login","Login Successfully");
        ui->stackedWidget->setCurrentIndex(3);
        ui->Email_input_login->clear();
        ui->Password_input_login->clear();
        ui->label_9->setText(query1.value(0).toString());
        ui->label_101->setText(query1.value(0).toString());
        ui->label_101->setAutoFillBackground(0);
        ui->label_103->setText(query1.value(1).toString());
        ui->label_105->setText(query1.value(3).toString());
        ui->label_107->setText(query1.value(5).toString());
        ui->label_109->setText(query1.value(6).toString());
        QPixmap pix(query1.value(4).toString());
        int w=ui->label_110->width();
        int h=ui->label_110->height();
        ui->label_110->setPixmap(pix.scaled(w,h,Qt::IgnoreAspectRatio,Qt::SmoothTransformation)); /// image of user
    }
    else {
        QMessageBox::warning(this,"Login","Wrong Email & Password");
        /// QMessageBox::critical(this,"Login","Wrong Email & Password");
    }
    }
}

void MainWindow::on_Sign_in_back_button_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
    ui->Name_input_sign_up->clear();
    ui->Email_input_sign_up->clear();
    ui->Mobile_input_sign_up->clear();
    ui->Password_input_sign_up->clear();
    ui->Conf_pass_input_sign_up->clear();
}


void MainWindow::on_Login_back_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->Email_input_login->clear();
    ui->Password_input_login->clear();
}
void MainWindow::on_Search_button_clicked()
{
    seat_available=count=0;
    from=ui->From_combobox->currentText();
    to=ui->To_combobox->currentText();
    if(from==to)
        QMessageBox::warning(this,"Error","Destinations can't be same");
    else {
        ui->stackedWidget->setCurrentIndex(4);
        ui->label_14->setText(from);
        ui->label_16->setText(to);
        conf_password="";seat_left="";
        QSqlQuery query1;
    query1.exec("SELECT * FROM bus WHERE num = '1'  AND book ='1' ");
    if(query1.next())
    {
        ui->A1_1->setText("A1    🟨");count++;
        ui->A1_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture36.png);");
    }
    query1.exec("SELECT * FROM bus WHERE num = '2'  AND book ='1' ");
    if(query1.next())
    {
        ui->A2_1->setText("A2    🟨");count++;
        ui->A2_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture36.png);");
    }
    query1.exec("SELECT * FROM bus WHERE num = '3'  AND book ='1' ");
    if(query1.next())
    {
        ui->A3_1->setText("A3    🟨");count++;
        ui->A3_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture36.png);");
    }
    query1.exec("SELECT * FROM bus WHERE num = '4'  AND book ='1' ");
    if(query1.next())
    {
        ui->A4_1->setText("A1    4");count++;
        ui->A4_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture36.png);");
    }
    query1.exec("SELECT * FROM bus WHERE num = '5'  AND book ='1' ");
    if(query1.next())
    {
        ui->B1_1->setText("B1    🟨");count++;
        ui->B1_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture36.png);");
    }
    query1.exec("SELECT * FROM bus WHERE num = '6'  AND book ='1' ");
    if(query1.next())
    {
        ui->B2_1->setText("B2    🟨");count++;
        ui->B2_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture36.png);");
    }
    query1.exec("SELECT * FROM bus WHERE num = '7'  AND book ='1' ");
    if(query1.next())
    {
        ui->B3_1->setText("B3    🟨");count++;
        ui->B3_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture36.png);");
    }
    query1.exec("SELECT * FROM bus WHERE num = '8'  AND book ='1' ");
    if(query1.next())
    {
        ui->B4_1->setText("B4    🟨");count++;
        ui->B4_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture36.png);");
    }
    query1.exec("SELECT * FROM bus WHERE num = '9'  AND book ='1' ");
    if(query1.next())
    {
        ui->C1_1->setText("C1    🟨");count++;
        ui->C1_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture36.png);");
    }
    query1.exec("SELECT * FROM bus WHERE num = '10'  AND book ='1' ");
    if(query1.next())
    {
        ui->C2_1->setText("C2    🟨");count++;
        ui->C2_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture36.png);");
    }
    query1.exec("SELECT * FROM bus WHERE num = '11'  AND book ='1' ");
    if(query1.next())
    {
        ui->C3_1->setText("C3    🟨");count++;
        ui->C3_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture36.png);");
    }
    query1.exec("SELECT * FROM bus WHERE num = '12'  AND book ='1' ");
    if(query1.next())
    {
        ui->C4_1->setText("C4    🟨");count++;
        ui->C4_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture36.png);");
    }
    query1.exec("SELECT * FROM bus WHERE num = '13'  AND book ='1' ");
    if(query1.next())
    {
        ui->D1_1->setText("D1    🟨");count++;
        ui->D1_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture36.png);");
    }
    query1.exec("SELECT * FROM bus WHERE num = '14'  AND book ='1' ");
    if(query1.next())
    {
        ui->D2_1->setText("D2    🟨");count++;
        ui->D2_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture36.png);");
    }
    query1.exec("SELECT * FROM bus WHERE num = '15'  AND book ='1' ");
    if(query1.next())
    {
        ui->D3_1->setText("D3    🟨");count++;
        ui->D3_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture36.png);");
    }
    query1.exec("SELECT * FROM bus WHERE num = '16'  AND book ='1' ");
    if(query1.next())
    {
        ui->D4_1->setText("D4    🟨");count++;
        ui->D4_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture36.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '17'  AND book ='1' ");
    if(query1.next())
    {
        ui->E1_1->setText("E1    🟨");count++;
        ui->E1_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture36.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '18'  AND book ='1' ");
    if(query1.next())
       {
        ui->E2_1->setText("E2    🟨");count++;
        ui->E2_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture36.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '19'  AND book ='1' ");
    if(query1.next())
       {
        ui->E3_1->setText("E3    🟨");count++;
        ui->E3_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture36.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '20'  AND book ='1' ");
    if(query1.next())
      {
        ui->E4_1->setText("E4    🟨");count++;
        ui->E4_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture36.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '21'  AND book ='1' ");
    if(query1.next())
       {
        ui->F1_1->setText("F1    🟨");count++;
        ui->F1_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture36.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '22'  AND book ='1' ");
    if(query1.next())
        {
        ui->F2_1->setText("F2    🟨");count++;
        ui->F2_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture36.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '23'  AND book ='1' ");
    if(query1.next())
    {
        ui->F3_1->setText("F3    🟨");count++;
        ui->F3_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture36.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '24'  AND book ='1' ");
    if(query1.next())
       {
        ui->F4_1->setText("F4    🟨");count++;
        ui->F4_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture36.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '25'  AND book ='1' ");
    if(query1.next())
      {
        ui->G1_1->setText("G1    🟨");count++;
        ui->G1_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture36.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '26'  AND book ='1' ");
    if(query1.next())
      {
        ui->G2_1->setText("G2    🟨");count++;
        ui->G2_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture36.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '27'  AND book ='1' ");
    if(query1.next())
       {
        ui->G3_1->setText("G3    🟨");count++;
        ui->G3_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture36.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '28'  AND book ='1' ");
    if(query1.next())
       {
        ui->G4_1->setText("G4    🟨");count++;
        ui->G4_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture36.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '29'  AND book ='1' ");
    if(query1.next())
      {
        ui->H1_1->setText("H1    🟨");count++;
        ui->H1_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture36.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '30'  AND book ='1' ");
    if(query1.next())
      {
        ui->H2_1->setText("H2    🟨");count++;
        ui->H2_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture36.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '31'  AND book ='1' ");
    if(query1.next())
       {
        ui->H3_1->setText("H3    🟨");count++;
        ui->H3_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture36.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '32'  AND book ='1' ");
    if(query1.next())
       {
        ui->H4_1->setText("H4    🟨");count++;
        ui->H4_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture36.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '33'  AND book ='1' ");
    if(query1.next())
      {
        ui->I1_1->setText("I1    🟨");count++;
        ui->I1_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture36.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '34'  AND book ='1' ");
    if(query1.next())
      {
        ui->I2_1->setText("I2    🟨");count++;
        ui->I2_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture36.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '35'  AND book ='1' ");
    if(query1.next())
       {
        ui->I3_1->setText("I3    🟨");count++;
        ui->I3_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture36.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '36'  AND book ='1' ");
    if(query1.next())
      {
        ui->I4_1->setText("I4    🟨");count++;
        ui->I4_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture36.png);");}
    ///Here
    query1.exec("SELECT * FROM bus WHERE num = '1'  AND book ='2' ");
    if(query1.next())
    {
        ui->A1_1->setText("A1    🟥");count++;
        ui->A1_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture35.png);");
    }
    query1.exec("SELECT * FROM bus WHERE num = '2'  AND book ='2' ");
    if(query1.next())
    {
        ui->A2_1->setText("A2    🟥");count++;
        ui->A2_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture35.png);");
    }
    query1.exec("SELECT * FROM bus WHERE num = '3'  AND book ='2' ");
    if(query1.next())
    {
        ui->A3_1->setText("A3    🟥");count++;
        ui->A3_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture35.png);");
    }
    query1.exec("SELECT * FROM bus WHERE num = '4'  AND book ='2' ");
    if(query1.next())
    {
        ui->A4_1->setText("A4    🟥");count++;
        ui->A4_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture35.png);");
    }
    query1.exec("SELECT * FROM bus WHERE num = '5'  AND book ='2' ");
    if(query1.next())
    {
        ui->B1_1->setText("B1    🟥");count++;
        ui->B1_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture35.png);");
    }
    query1.exec("SELECT * FROM bus WHERE num = '6'  AND book ='2' ");
    if(query1.next())
    {
        ui->B2_1->setText("B2    🟥");count++;
        ui->B2_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture35.png);");
    }
    query1.exec("SELECT * FROM bus WHERE num = '7'  AND book ='2' ");
    if(query1.next())
    {
        ui->B3_1->setText("B3    🟥");count++;
        ui->B3_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture35.png);");
    }
    query1.exec("SELECT * FROM bus WHERE num = '8'  AND book ='2' ");
    if(query1.next())
    {
        ui->B4_1->setText("B4    🟥");count++;
        ui->B4_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture35.png);");
    }
    query1.exec("SELECT * FROM bus WHERE num = '9'  AND book ='2' ");
    if(query1.next())
    {
        ui->C1_1->setText("C1    🟥");count++;
        ui->C1_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture35.png);");
    }
    query1.exec("SELECT * FROM bus WHERE num = '10'  AND book ='2' ");
    if(query1.next())
    {
        ui->C2_1->setText("C2    🟥");count++;
        ui->C2_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture35.png);");
    }
    query1.exec("SELECT * FROM bus WHERE num = '11'  AND book ='2' ");
    if(query1.next())
    {
        ui->C3_1->setText("C3    🟥");count++;
        ui->C3_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture35.png);");
    }
    query1.exec("SELECT * FROM bus WHERE num = '12'  AND book ='2' ");
    if(query1.next())
    {
        ui->C4_1->setText("C4    🟥");count++;
        ui->C4_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture35.png);");
    }
    query1.exec("SELECT * FROM bus WHERE num = '13'  AND book ='2' ");
    if(query1.next())
    {
        ui->D1_1->setText("D1    🟥");count++;
        ui->D1_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture35.png);");
    }
    query1.exec("SELECT * FROM bus WHERE num = '14'  AND book ='2' ");
    if(query1.next())
    {
        ui->D2_1->setText("D2    🟥");count++;
        ui->D2_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture35.png);");
    }
    query1.exec("SELECT * FROM bus WHERE num = '15'  AND book ='2' ");
    if(query1.next())
    {
        ui->D3_1->setText("D3    🟥");count++;
        ui->D3_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture35.png);");
    }
    query1.exec("SELECT * FROM bus WHERE num = '16'  AND book ='2' ");
    if(query1.next())
    {
        ui->D4_1->setText("D4    🟥");count++;
        ui->D4_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture35.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '17'  AND book ='2' ");
    if(query1.next())
    {
        ui->E1_1->setText("E1    🟥");count++;
        ui->E1_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture35.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '18'  AND book ='2' ");
    if(query1.next())
    {
        ui->E2_1->setText("E2    🟥");count++;
        ui->E2_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture35.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '19'  AND book ='2' ");
    if(query1.next())
    {
        ui->E3_1->setText("E3    🟥");count++;
        ui->E3_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture35.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '20'  AND book ='2' ");
    if(query1.next())
    {
        ui->E4_1->setText("E4    🟥");count++;
        ui->E4_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture35.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '21'  AND book ='2' ");
    if(query1.next())
    {
        ui->F1_1->setText("F1    🟥");count++;
        ui->F1_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture35.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '22'  AND book ='2' ");
    if(query1.next())
    {
        ui->F2_1->setText("F2    🟥");count++;
        ui->F2_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture35.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '23'  AND book ='2' ");
    if(query1.next())
    {
        ui->F3_1->setText("F3    🟥");count++;
        ui->F3_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture35.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '24'  AND book ='2' ");
    if(query1.next())
    {
        ui->F4_1->setText("F4    🟥");count++;
        ui->F4_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture35.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '25'  AND book ='2' ");
    if(query1.next())
    {
        ui->G1_1->setText("G1    🟥");count++;
        ui->G1_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture35.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '26'  AND book ='2' ");
    if(query1.next())
    {
        ui->G2_1->setText("G2    🟥");count++;
        ui->G2_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture35.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '27'  AND book ='2' ");
    if(query1.next())
    {
        ui->G3_1->setText("G3    🟥");count++;
        ui->G3_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture35.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '28'  AND book ='2' ");
    if(query1.next())
    {
        ui->G4_1->setText("G4    🟥");count++;
        ui->G4_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture35.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '29'  AND book ='2' ");
    if(query1.next())
    {
        ui->H1_1->setText("H1    🟥");count++;
        ui->H1_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture35.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '30'  AND book ='2' ");
    if(query1.next())
    {
        ui->H2_1->setText("H2    🟥");count++;
        ui->H2_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture35.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '31'  AND book ='2' ");
    if(query1.next())
    {
        ui->H3_1->setText("H3    🟥");count++;
        ui->H3_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture35.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '32'  AND book ='2' ");
    if(query1.next())
    {
        ui->H4_1->setText("H4    🟥");count++;
        ui->H4_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture35.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '33'  AND book ='2' ");
    if(query1.next())
    {
        ui->I1_1->setText("I1    🟥");count++;
        ui->I1_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture35.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '34'  AND book ='2' ");
    if(query1.next())
    {
        ui->I2_1->setText("I2    🟥");count++;
        ui->I2_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture35.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '35'  AND book ='2' ");
    if(query1.next())
    {
        ui->I3_1->setText("I3    🟥");count++;
        ui->I3_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture35.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '36'  AND book ='2' ");
    if(query1.next())
    {
        ui->I4_1->setText("I4    🟥");count++;
        ui->I4_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture35.png);");}
    ///there
    query1.exec("SELECT * FROM bus WHERE num = '1'  AND book ='0' ");
    if(query1.next())
    {
        ui->A1_1->setText("A1    ");
        ui->A1_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");
    }
    query1.exec("SELECT * FROM bus WHERE num = '2'  AND book ='0' ");
    if(query1.next())
    {
        ui->A2_1->setText("A2    ");
        ui->A2_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");
    }
    query1.exec("SELECT * FROM bus WHERE num = '3'  AND book ='0' ");
    if(query1.next())
    {
        ui->A3_1->setText("A3    ");
        ui->A3_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");
    }
    query1.exec("SELECT * FROM bus WHERE num = '4'  AND book ='0' ");
    if(query1.next())
    {
        ui->A4_1->setText("A4    ");
        ui->A4_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");
    }
    query1.exec("SELECT * FROM bus WHERE num = '5'  AND book ='0' ");
    if(query1.next())
    {
        ui->B1_1->setText("B1    ");
        ui->B1_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");
    }
    query1.exec("SELECT * FROM bus WHERE num = '6'  AND book ='0' ");
    if(query1.next())
    {
        ui->B2_1->setText("B2    ");
        ui->B2_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");
    }
    query1.exec("SELECT * FROM bus WHERE num = '7'  AND book ='0' ");
    if(query1.next())
    {
        ui->B3_1->setText("B3    ");
        ui->B3_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");
    }
    query1.exec("SELECT * FROM bus WHERE num = '8'  AND book ='0' ");
    if(query1.next())
    {
        ui->B4_1->setText("B4    ");
        ui->B4_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");
    }
    query1.exec("SELECT * FROM bus WHERE num = '9'  AND book ='0' ");
    if(query1.next())
    {
        ui->C1_1->setText("C1    ");
        ui->C1_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");
    }
    query1.exec("SELECT * FROM bus WHERE num = '10'  AND book ='0' ");
    if(query1.next())
    {
        ui->C2_1->setText("C2    ");
        ui->C2_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");
    }
    query1.exec("SELECT * FROM bus WHERE num = '11'  AND book ='0' ");
    if(query1.next())
    {
        ui->C3_1->setText("C3    ");
        ui->C3_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");
    }
    query1.exec("SELECT * FROM bus WHERE num = '12'  AND book ='0' ");
    if(query1.next())
    {
        ui->C4_1->setText("C4    ");
        ui->C4_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");
    }
    query1.exec("SELECT * FROM bus WHERE num = '13'  AND book ='0' ");
    if(query1.next())
    {
        ui->D1_1->setText("D1    ");
        ui->D1_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");
    }
    query1.exec("SELECT * FROM bus WHERE num = '14'  AND book ='0' ");
    if(query1.next())
    {
        ui->D2_1->setText("D2    ");
        ui->D2_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");
    }
    query1.exec("SELECT * FROM bus WHERE num = '15'  AND book ='0' ");
    if(query1.next())
    {
        ui->D3_1->setText("D3    ");
        ui->D3_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");
    }
    query1.exec("SELECT * FROM bus WHERE num = '16'  AND book ='0' ");
    if(query1.next())
    {
        ui->D4_1->setText("D4    ");
        ui->D4_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '17'  AND book ='0' ");
    if(query1.next())
    {
        ui->E1_1->setText("E1    ");
        ui->E1_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '18'  AND book ='0' ");
    if(query1.next())
    {
        ui->E2_1->setText("E2    ");
        ui->E2_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '19'  AND book ='0' ");
    if(query1.next())
    {
        ui->E3_1->setText("E3    ");
        ui->E3_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '20'  AND book ='0' ");
    if(query1.next())
    {
        ui->E4_1->setText("E4    ");
        ui->E4_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '21'  AND book ='0' ");
    if(query1.next())
    {
        ui->F1_1->setText("F1    ");
        ui->F1_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '22'  AND book ='0' ");
    if(query1.next())
    {
        ui->F2_1->setText("F2    ");
        ui->F2_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '23'  AND book ='0' ");
    if(query1.next())
    {
        ui->F3_1->setText("F3    ");
        ui->F3_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture36.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '24'  AND book ='0' ");
    if(query1.next())
    {
        ui->F4_1->setText("F4    ");
        ui->F4_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture36.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '25'  AND book ='0' ");
    if(query1.next())
    {
        ui->G1_1->setText("G1    ");
        ui->G1_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture36.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '26'  AND book ='0' ");
    if(query1.next())
    {
        ui->G2_1->setText("G2    ");
        ui->G2_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture36.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '27'  AND book ='0' ");
    if(query1.next())
    {
        ui->G3_1->setText("G3    ");
        ui->G3_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture36.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '28'  AND book ='0' ");
    if(query1.next())
    {
        ui->G4_1->setText("G4    ");
        ui->G4_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture36.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '29'  AND book ='0' ");
    if(query1.next())
    {
        ui->H1_1->setText("H1    ");
        ui->H1_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture36.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '30'  AND book ='0' ");
    if(query1.next())
    {
        ui->H2_1->setText("H2    ");
        ui->H2_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture36.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '31'  AND book ='0' ");
    if(query1.next())
    {
        ui->H3_1->setText("H3    ");
        ui->H3_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture36.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '32'  AND book ='0' ");
    if(query1.next())
    {
        ui->H4_1->setText("H4    ");
        ui->H4_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture36.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '33'  AND book ='0' ");
    if(query1.next())
    {
        ui->I1_1->setText("I1    ");
        ui->I1_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture36.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '34'  AND book ='0' ");
    if(query1.next())
    {
        ui->I2_1->setText("I2    ");
        ui->I2_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture36.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '35'  AND book ='0' ");
    if(query1.next())
    {
        ui->I3_1->setText("I3    ");
        ui->I3_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture36.png);");}
    query1.exec("SELECT * FROM bus WHERE num = '36'  AND book ='0' ");
    if(query1.next())
    {
        ui->I4_1->setText("I4    ");
        ui->I4_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture36.png);");}
    /// last
    count=36-count;
    seat_left+="          ";seat_left+=QString::number(count);seat_left+=" seats left";
    ui->label_17->setText(seat_left);
    seat_left="";
    QSqlQueryModel *modal=new QSqlQueryModel();
    QSqlQuery* qry=new QSqlQuery(database);
    qry->prepare("select * from shedule");
    qry->exec();
    modal->setQuery(*qry);
    QTableView *tableview=new QTableView(this);
    QStandardItemModel *model =new QStandardItemModel(this);
    ui->Bus_tableview->setModel(model);
    ui->Bus_tableview->setModel(modal);

    qDebug()<< modal->rowCount();
    }
}

void MainWindow::on_pushButton_13_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_Buy1_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_A1_1_stateChanged(int arg1)
{
    conf_password="";
    conf_password=ui->A1_1->text();
    if(conf_password=="A1    🟥")
        {QMessageBox::information(this,"Seat Select","This seat has been booked\nPlease select other seat");ui->A1_1->setChecked(false);}
    else if(conf_password=="A1    🟨")
        {QMessageBox::information(this,"Seat Select","This seat has already been requested\nPlease select other seat");ui->A1_1->setChecked(false);}
    else if(arg1)
     {
        if((int)seat_left.size()==12)
        {
            QMessageBox::warning(this,"Limit","You are maximum allowed to select 4 seats");
        }
        else
        {
            ui->A1_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture388.png);");
            seat_left=ui->label_87->text();
            seat_left+="A1 ";
            ui->label_87->setText(seat_left);
        }
     }
     else {
        ui->A1_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");
        seat_left=ui->label_87->text();
        for(int i=0;i<seat_left.size();i++)
        {
            if(seat_left[i]=='A' && seat_left[i+1]=='1')
            {
                seat_left.remove(i,3);

            }
        }
        ui->label_87->setText(seat_left);
     }
}


void MainWindow::on_A2_1_stateChanged(int arg1)
{
    conf_password="";
    conf_password=ui->A2_1->text();
    if(conf_password=="A2    🟥")
        {QMessageBox::information(this,"Seat Select","This seat has been booked\nPlease select other seat");ui->A2_1->setChecked(false);}
    else if(conf_password=="A2    🟨")
       { QMessageBox::information(this,"Seat Select","This seat has already been requested\nPlease select other seat");ui->A2_1->setChecked(false);}
    else if(arg1)
     {
        if((int)seat_left.size()==12)
        {
            QMessageBox::warning(this,"Limit","You are maximum allowed to select 4 seats");
        }
        else
        {
            ui->A2_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture388.png);");
            seat_left=ui->label_87->text();
            seat_left+="A2 ";
            ui->label_87->setText(seat_left);
        }
     }
     else {
        ui->A2_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");
        seat_left=ui->label_87->text();
        int i;
        for(i=0;i<seat_left.size();i++)
        {
            if(seat_left[i]=='A' && seat_left[i+1]=='2')
            {
                seat_left.remove(i,3);

            }
        }
        ui->label_87->setText(seat_left);
     }
}


void MainWindow::on_B1_1_stateChanged(int arg1)
{
     conf_password="";
     conf_password=ui->B1_1->text();
     if(conf_password=="B1    🟥")
        {QMessageBox::information(this,"Seat Select","This seat has been booked\nPlease select other seat");ui->B1_1->setChecked(false);}
     else if(conf_password=="B1    🟨")
       { QMessageBox::information(this,"Seat Select","This seat has already been requested\nPlease select other seat");ui->B1_1->setChecked(false);}
    else if(arg1)
     {
        if((int)seat_left.size()==12)
        {
            QMessageBox::warning(this,"Limit","You are maximum allowed to select 4 seats");
        }
        else
        {
            ui->B1_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture388.png);");

            seat_left=ui->label_87->text();
            seat_left+="B1 ";
            ui->label_87->setText(seat_left);
        }
     }
     else {
        ui->B1_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");
        seat_left=ui->label_87->text();
        int i;
        for(i=0;i<seat_left.size();i++)
        {
            if(seat_left[i]=='B' && seat_left[i+1]=='1')
            {
                seat_left.remove(i,3);

            }
        }
        ui->label_87->setText(seat_left);
     }
}


void MainWindow::on_C1_1_stateChanged(int arg1)
{
     conf_password="";
     conf_password=ui->C1_1->text();
     if(conf_password=="C1    🟥")
        {QMessageBox::information(this,"Seat Select","This seat has been booked\nPlease select other seat");ui->C1_1->setChecked(false);}
     else if(conf_password=="C1    🟨")
      {  QMessageBox::information(this,"Seat Select","This seat has already been requested\nPlease select other seat");ui->C1_1->setChecked(false);}
    else if(arg1)
     {
        if((int)seat_left.size()==12)
        {
            QMessageBox::warning(this,"Limit","You are maximum allowed to select 4 seats");
        }
        else
        {
            ui->C1_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture388.png);");

            seat_left=ui->label_87->text();
            seat_left+="C1 ";
            ui->label_87->setText(seat_left);
        }
     }
     else {
        ui->C1_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");
        seat_left=ui->label_87->text();
        int i;
        for(i=0;i<seat_left.size();i++)
        {
            if(seat_left[i]=='C' && seat_left[i+1]=='1')
            {
                seat_left.remove(i,3);

            }
        }
        ui->label_87->setText(seat_left);
     }
}


void MainWindow::on_D1_1_stateChanged(int arg1)
{
     conf_password="";
     conf_password=ui->D1_1->text();
     if(conf_password=="D1    🟥")
        {QMessageBox::information(this,"Seat Select","This seat has been booked\nPlease select other seat");ui->D1_1->setChecked(false);}
     else if(conf_password=="D1    🟨")
      {  QMessageBox::information(this,"Seat Select","This seat has already been requested\nPlease select other seat");ui->D1_1->setChecked(false);}
    else if(arg1)
     {
        if((int)seat_left.size()==12)
        {
            QMessageBox::warning(this,"Limit","You are maximum allowed to select 4 seats");
        }
        else
        {
            ui->D1_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture388.png);");

            seat_left=ui->label_87->text();
            seat_left+="D1 ";
            ui->label_87->setText(seat_left);
        }
     }
     else {
        ui->D1_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");
        seat_left=ui->label_87->text();
        int i;
        for(i=0;i<seat_left.size();i++)
        {
            if(seat_left[i]=='D' && seat_left[i+1]=='1')
            {
                seat_left.remove(i,3);

            }
        }
        ui->label_87->setText(seat_left);
     }
}


void MainWindow::on_E1_1_stateChanged(int arg1)
{
     conf_password="";
     conf_password=ui->E1_1->text();
     if(conf_password=="E1    🟥")
        {QMessageBox::information(this,"Seat Select","This seat has been booked\nPlease select other seat");ui->E1_1->setChecked(false);}
     else if(conf_password=="E1    🟨")
      {  QMessageBox::information(this,"Seat Select","This seat has already been requested\nPlease select other seat");ui->E1_1->setChecked(false);}
    else if(arg1)
     {
        if((int)seat_left.size()==12)
        {
            QMessageBox::warning(this,"Limit","You are maximum allowed to select 4 seats");
        }
        else
        {
            ui->E1_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture388.png);");

            seat_left=ui->label_87->text();
            seat_left+="E1 ";
            ui->label_87->setText(seat_left);
        }
     }
     else {
        ui->E1_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");
        seat_left=ui->label_87->text();
        int i;
        for(i=0;i<seat_left.size();i++)
        {
            if(seat_left[i]=='E' && seat_left[i+1]=='1')
            {
                seat_left.remove(i,3);

            }
        }
        ui->label_87->setText(seat_left);
     }
}


void MainWindow::on_F1_1_stateChanged(int arg1)
{
     conf_password="";
     conf_password=ui->F1_1->text();
     if(conf_password=="F1    🟥")
        {QMessageBox::information(this,"Seat Select","This seat has been booked\nPlease select other seat");ui->F1_1->setChecked(false);}
     else if(conf_password=="F1    🟨")
      {  QMessageBox::information(this,"Seat Select","This seat has already been requested\nPlease select other seat");ui->F1_1->setChecked(false);}
    else if(arg1)
     {
        if((int)seat_left.size()==12)
        {
            QMessageBox::warning(this,"Limit","You are maximum allowed to select 4 seats");
        }
        else
        {
            ui->F1_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture388.png);");

            seat_left=ui->label_87->text();
            seat_left+="F1 ";
            ui->label_87->setText(seat_left);
        }
     }
     else {
        ui->F1_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");
        seat_left=ui->label_87->text();
        int i;
        for(i=0;i<seat_left.size();i++)
        {
            if(seat_left[i]=='F' && seat_left[i+1]=='1')
            {
                seat_left.remove(i,3);

            }
        }
        ui->label_87->setText(seat_left);
     }
}


void MainWindow::on_G1_1_stateChanged(int arg1)
{
     conf_password="";
     conf_password=ui->G1_1->text();
     if(conf_password=="G1    🟥")
        {QMessageBox::information(this,"Seat Select","This seat has been booked\nPlease select other seat");ui->G1_1->setChecked(false);}
     else if(conf_password=="G1    🟨")
      {  QMessageBox::information(this,"Seat Select","This seat has already been requested\nPlease select other seat");ui->G1_1->setChecked(false);}
    else if(arg1)
     {
        if((int)seat_left.size()==12)
        {
            QMessageBox::warning(this,"Limit","You are maximum allowed to select 4 seats");
        }
        else
        {
            ui->G1_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture388.png);");

            seat_left=ui->label_87->text();
            seat_left+="G1 ";
            ui->label_87->setText(seat_left);
        }
     }
     else {
        ui->G1_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");
        seat_left=ui->label_87->text();
        int i;
        for(i=0;i<seat_left.size();i++)
        {
            if(seat_left[i]=='G' && seat_left[i+1]=='1')
            {
                seat_left.remove(i,3);

            }
        }
        ui->label_87->setText(seat_left);
     }
}


void MainWindow::on_H1_1_stateChanged(int arg1)
{
     conf_password="";
     conf_password=ui->H1_1->text();
     if(conf_password=="H1    🟥")
        {QMessageBox::information(this,"Seat Select","This seat has been booked\nPlease select other seat");ui->H1_1->setChecked(false);}
     else if(conf_password=="H1    🟨")
     {   QMessageBox::information(this,"Seat Select","This seat has already been requested\nPlease select other seat");ui->H1_1->setChecked(false);}
    else if(arg1)
     {
        if((int)seat_left.size()==12)
        {
            QMessageBox::warning(this,"Limit","You are maximum allowed to select 4 seats");
        }
        else
        {
            ui->H1_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture388.png);");

            seat_left=ui->label_87->text();
            seat_left+="H1 ";
            ui->label_87->setText(seat_left);
        }
     }
     else {
        ui->H1_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");
        seat_left=ui->label_87->text();
        int i;
        for(i=0;i<seat_left.size();i++)
        {
            if(seat_left[i]=='H' && seat_left[i+1]=='1')
            {
                seat_left.remove(i,3);

            }
        }
        ui->label_87->setText(seat_left);
     }
}


void MainWindow::on_I1_1_stateChanged(int arg1)
{
     conf_password="";
     conf_password=ui->I1_1->text();
     if(conf_password=="I1    🟥")
        {QMessageBox::information(this,"Seat Select","This seat has been booked\nPlease select other seat");ui->I1_1->setChecked(false);}
     else if(conf_password=="I1    🟨")
      {  QMessageBox::information(this,"Seat Select","This seat has already been requested\nPlease select other seat");ui->I1_1->setChecked(false);}
    else if(arg1)
     {
        if((int)seat_left.size()==12)
        {
            QMessageBox::warning(this,"Limit","You are maximum allowed to select 4 seats");
        }
        else
        {
            ui->I1_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture388.png);");

            seat_left=ui->label_87->text();
            seat_left+="I1 ";
            ui->label_87->setText(seat_left);
        }
     }
     else {
        ui->I1_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");
        seat_left=ui->label_87->text();
        int i;
        for(i=0;i<seat_left.size();i++)
        {
            if(seat_left[i]=='I' && seat_left[i+1]=='1')
            {
                seat_left.remove(i,3);

            }
        }
        ui->label_87->setText(seat_left);
     }
}


void MainWindow::on_B2_1_stateChanged(int arg1)
{
     conf_password="";
     conf_password=ui->B2_1->text();
     if(conf_password=="B2    🟥")
        {QMessageBox::information(this,"Seat Select","This seat has been booked\nPlease select other seat");ui->B2_1->setChecked(false);}
     else if(conf_password=="B2    🟨")
      {  QMessageBox::information(this,"Seat Select","This seat has already been requested\nPlease select other seat");ui->B2_1->setChecked(false);}
    else if(arg1)
     {
        if((int)seat_left.size()==12)
        {
            QMessageBox::warning(this,"Limit","You are maximum allowed to select 4 seats");
        }
        else
        {
            ui->B2_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture388.png);");

            seat_left=ui->label_87->text();
            seat_left+="B2 ";
            ui->label_87->setText(seat_left);
        }
     }
     else {
        ui->B2_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");
        seat_left=ui->label_87->text();
        int i;
        for(i=0;i<seat_left.size();i++)
        {
            if(seat_left[i]=='B' && seat_left[i+1]=='2')
            {
                seat_left.remove(i,3);

            }
        }
        ui->label_87->setText(seat_left);
     }
}


void MainWindow::on_C2_1_stateChanged(int arg1)
{
     conf_password="";
     conf_password=ui->C2_1->text();
     if(conf_password=="C2    🟥")
        {QMessageBox::information(this,"Seat Select","This seat has been booked\nPlease select other seat");ui->C2_1->setChecked(false);}
     else if(conf_password=="C2    🟨")
      {  QMessageBox::information(this,"Seat Select","This seat has already been requested\nPlease select other seat");ui->C2_1->setChecked(false);}
    else if(arg1)
     {
        if((int)seat_left.size()==12)
        {
            QMessageBox::warning(this,"Limit","You are maximum allowed to select 4 seats");
        }
        else
        {
            ui->C2_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture388.png);");

            seat_left=ui->label_87->text();
            seat_left+="C2 ";
            ui->label_87->setText(seat_left);
        }
     }
     else {
        ui->C2_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");
        seat_left=ui->label_87->text();
        int i;
        for(i=0;i<seat_left.size();i++)
        {
            if(seat_left[i]=='C' && seat_left[i+1]=='2')
            {
                seat_left.remove(i,3);

            }
        }
        ui->label_87->setText(seat_left);
     }
}


void MainWindow::on_D2_1_stateChanged(int arg1)
{
     conf_password="";
     conf_password=ui->D2_1->text();
     if(conf_password=="D2    🟥")
        {QMessageBox::information(this,"Seat Select","This seat has been booked\nPlease select other seat");ui->D2_1->setChecked(false);}
     else if(conf_password=="D2    🟨")
      {  QMessageBox::information(this,"Seat Select","This seat has already been requested\nPlease select other seat");ui->D2_1->setChecked(false);}
    else if(arg1)
     {
        if((int)seat_left.size()==12)
        {
            QMessageBox::warning(this,"Limit","You are maximum allowed to select 4 seats");
        }
        else
        {
            ui->D2_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture388.png);");
            seat_left=ui->label_87->text();
            seat_left+="D2 ";
            ui->label_87->setText(seat_left);
        }
     }
     else {
       ui->D2_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");
        seat_left=ui->label_87->text();
        int i;
        for(i=0;i<seat_left.size();i++)
        {
            if(seat_left[i]=='D' && seat_left[i+1]=='2')
            {
                seat_left.remove(i,3);

            }
        }
        ui->label_87->setText(seat_left);
     }
}


void MainWindow::on_E2_1_stateChanged(int arg1)
{
     conf_password="";
     conf_password=ui->E2_1->text();
     if(conf_password=="E2    🟥")
        {QMessageBox::information(this,"Seat Select","This seat has been booked\nPlease select other seat");ui->E2_1->setChecked(false);}
     else if(conf_password=="E2    🟨")
      {  QMessageBox::information(this,"Seat Select","This seat has already been requested\nPlease select other seat");ui->E2_1->setChecked(false);}
    else if(arg1)
     {
        if((int)seat_left.size()==12)
        {
            QMessageBox::warning(this,"Limit","You are maximum allowed to select 4 seats");
        }
        else
        {
            ui->E2_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture388.png);");
            seat_left=ui->label_87->text();
            seat_left+="E2 ";
            ui->label_87->setText(seat_left);
        }
     }
     else {
        ui->E2_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");
        seat_left=ui->label_87->text();
        int i;
        for(i=0;i<seat_left.size();i++)
        {
            if(seat_left[i]=='E' && seat_left[i+1]=='2')
            {
                seat_left.remove(i,3);

            }
        }
        ui->label_87->setText(seat_left);
     }
}


void MainWindow::on_F2_1_stateChanged(int arg1)
{
     conf_password="";
     conf_password=ui->F2_1->text();
     if(conf_password=="F2    🟥")
        {QMessageBox::information(this,"Seat Select","This seat has been booked\nPlease select other seat");ui->F2_1->setChecked(false);}
     else if(conf_password=="F2    🟨")
       { QMessageBox::information(this,"Seat Select","This seat has already been requested\nPlease select other seat");ui->F2_1->setChecked(false);}
    else if(arg1)
     {
        if((int)seat_left.size()==12)
        {
            QMessageBox::warning(this,"Limit","You are maximum allowed to select 4 seats");
        }
        else
        {
            ui->F2_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture388.png);");
            seat_left=ui->label_87->text();
            seat_left+="F2 ";
            ui->label_87->setText(seat_left);
        }
     }
     else {
       ui->F2_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");
        seat_left=ui->label_87->text();
        int i;
        for(i=0;i<seat_left.size();i++)
        {
            if(seat_left[i]=='F' && seat_left[i+1]=='2')
            {
                seat_left.remove(i,3);

            }
        }
        ui->label_87->setText(seat_left);
     }
}


void MainWindow::on_G2_1_stateChanged(int arg1)
{
     conf_password="";
     conf_password=ui->G2_1->text();
     if(conf_password=="G2    🟥")
        {QMessageBox::information(this,"Seat Select","This seat has been booked\nPlease select other seat");ui->G2_1->setChecked(false);}
     else if(conf_password=="G2    🟨")
      {  QMessageBox::information(this,"Seat Select","This seat has already been requested\nPlease select other seat");ui->G2_1->setChecked(false);}
    else if(arg1)
     {
        if((int)seat_left.size()==12)
        {
            QMessageBox::warning(this,"Limit","You are maximum allowed to select 4 seats");
        }
        else
        {
            ui->G2_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture388.png);");
            seat_left=ui->label_87->text();
            seat_left+="G2 ";
            ui->label_87->setText(seat_left);
        }
     }
     else {
        ui->G2_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");
        seat_left=ui->label_87->text();
        int i;
        for(i=0;i<seat_left.size();i++)
        {
            if(seat_left[i]=='G' && seat_left[i+1]=='2')
            {
                seat_left.remove(i,3);

            }
        }
        ui->label_87->setText(seat_left);
     }
}


void MainWindow::on_H2_1_stateChanged(int arg1)
{
     conf_password="";
     conf_password=ui->H2_1->text();
     if(conf_password=="H2    🟥")
        {QMessageBox::information(this,"Seat Select","This seat has been booked\nPlease select other seat");ui->H2_1->setChecked(false);}
     else if(conf_password=="H2    🟨")
      {  QMessageBox::information(this,"Seat Select","This seat has already been requested\nPlease select other seat");ui->H2_1->setChecked(false);}
    else if(arg1)
     {
        if((int)seat_left.size()==12)
        {
            QMessageBox::warning(this,"Limit","You are maximum allowed to select 4 seats");
        }
        else
        {
            ui->H2_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture388.png);");
            seat_left=ui->label_87->text();
            seat_left+="H2 ";
            ui->label_87->setText(seat_left);
        }
     }
     else {
        ui->H2_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");
        seat_left=ui->label_87->text();
        int i;
        for(i=0;i<seat_left.size();i++)
        {
            if(seat_left[i]=='H' && seat_left[i+1]=='2')
            {
                seat_left.remove(i,3);

            }
        }
        ui->label_87->setText(seat_left);
     }
}


void MainWindow::on_I2_1_stateChanged(int arg1)
{
     conf_password="";
     conf_password=ui->I2_1->text();
     if(conf_password=="I2    🟥")
        {QMessageBox::information(this,"Seat Select","This seat has been booked\nPlease select other seat");ui->I2_1->setChecked(false);}
     else if(conf_password=="I2    🟨")
      {  QMessageBox::information(this,"Seat Select","This seat has already been requested\nPlease select other seat");ui->I2_1->setChecked(false);}
    else if(arg1)
     {
        if((int)seat_left.size()==12)
        {
            QMessageBox::warning(this,"Limit","You are maximum allowed to select 4 seats");
        }
        else
        {
            ui->I2_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture388.png);");
            seat_left=ui->label_87->text();
            seat_left+="I2 ";
            ui->label_87->setText(seat_left);
        }
     }
     else {
        ui->I2_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");
        seat_left=ui->label_87->text();
        int i;
        for(i=0;i<seat_left.size();i++)
        {
            if(seat_left[i]=='I' && seat_left[i+1]=='2')
            {
                seat_left.remove(i,3);

            }
        }
        ui->label_87->setText(seat_left);
     }
}


void MainWindow::on_A3_1_stateChanged(int arg1)
{
     conf_password="";
     conf_password=ui->A3_1->text();
     if(conf_password=="A3    🟥")
        {QMessageBox::information(this,"Seat Select","This seat has been booked\nPlease select other seat");ui->A3_1->setChecked(false);}
     else if(conf_password=="A3    🟨")
      {  QMessageBox::information(this,"Seat Select","This seat has already been requested\nPlease select other seat");ui->A3_1->setChecked(false);}
    else if(arg1)
     {
        if((int)seat_left.size()==12)
        {
            QMessageBox::warning(this,"Limit","You are maximum allowed to select 4 seats");
        }
        else
        {
            ui->A3_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture388.png);");
            seat_left=ui->label_87->text();
            seat_left+="A3 ";
            ui->label_87->setText(seat_left);
        }
     }
     else {
        ui->A3_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");
        seat_left=ui->label_87->text();
        int i;
        for(i=0;i<seat_left.size();i++)
        {
            if(seat_left[i]=='A' && seat_left[i+1]=='3')
            {
                seat_left.remove(i,3);

            }
        }
        ui->label_87->setText(seat_left);
     }
}


void MainWindow::on_B3_1_stateChanged(int arg1)
{
     conf_password="";
     conf_password=ui->B3_1->text();
     if(conf_password=="B3    🟥")
        {QMessageBox::information(this,"Seat Select","This seat has been booked\nPlease select other seat");ui->B3_1->setChecked(false);}
     else if(conf_password=="B3    🟨")
      {  QMessageBox::information(this,"Seat Select","This seat has already been requested\nPlease select other seat");ui->B3_1->setChecked(false);}
    else if(arg1)
     {
        if((int)seat_left.size()==12)
        {
            QMessageBox::warning(this,"Limit","You are maximum allowed to select 4 seats");
        }
        else
        {
            ui->B3_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture388.png);");
            seat_left=ui->label_87->text();
            seat_left+="B3 ";
            ui->label_87->setText(seat_left);
        }
     }
     else {
        ui->B3_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");
        seat_left=ui->label_87->text();
        int i;
        for(i=0;i<seat_left.size();i++)
        {
            if(seat_left[i]=='B' && seat_left[i+1]=='3')
            {
                seat_left.remove(i,3);

            }
        }
        ui->label_87->setText(seat_left);
     }
}


void MainWindow::on_C3_1_stateChanged(int arg1)
{
     conf_password="";
     conf_password=ui->C3_1->text();
     if(conf_password=="C3    🟥")
        {QMessageBox::information(this,"Seat Select","This seat has been booked\nPlease select other seat");ui->C3_1->setChecked(false);}
     else if(conf_password=="C3    🟨")
      {  QMessageBox::information(this,"Seat Select","This seat has already been requested\nPlease select other seat");ui->C3_1->setChecked(false);}
    else if(arg1)
     {
        if((int)seat_left.size()==12)
        {
            QMessageBox::warning(this,"Limit","You are maximum allowed to select 4 seats");
        }
        else
        {
            ui->C3_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture388.png);");
            seat_left=ui->label_87->text();
            seat_left+="C3 ";
            ui->label_87->setText(seat_left);
        }
     }
     else {
        ui->C3_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");
        seat_left=ui->label_87->text();
        int i;
        for(i=0;i<seat_left.size();i++)
        {
            if(seat_left[i]=='C' && seat_left[i+1]=='3')
            {
                seat_left.remove(i,3);

            }
        }
        ui->label_87->setText(seat_left);
     }
}

void MainWindow::on_Buy_tickets_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_My_tickets_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
    QSqlQueryModel *modal=new QSqlQueryModel();
    QSqlQuery* qry=new QSqlQuery(database);
    qry->exec("select * from admin_request");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView_2->setModel(modal);
}

void MainWindow::on_My_profile_back_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_17_clicked()
{
     ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_Log_out_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_Change_photo_button_clicked()
{
    //user selecting image here
    imagepath = QFileDialog::getOpenFileName(this,tr("Open Image"),"",tr("JPEG (*.jpg *.jpeg);;PNG (*png)")); //image select
    QPixmap picture(imagepath);
    //QPixmap picture("c:/Users/ProgrammingKnowledge/Pictures?qt_pic/login-icon.png); -> direct select
    int w=ui->label_110->width();
    int h=ui->label_110->height();
    ui->label_110->setPixmap(picture.scaled(w,h,Qt::IgnoreAspectRatio));  //Qt::KeepAspectRatio
    email=ui->label_103->text();
    //qDebug()<<email;
    QSqlQuery query1;
    query1.exec("UPDATE user SET image='"+imagepath+"' WHERE email = '"+email+"'");
    query1.next();
    QMessageBox::information(this,"Change Photo","Successfully Updated Photo");
}

void MainWindow::on_D3_1_stateChanged(int arg1)
{
     conf_password="";
     conf_password=ui->D3_1->text();
     if(conf_password=="D3    🟥")
        {QMessageBox::information(this,"Seat Select","This seat has been booked\nPlease select other seat");ui->D3_1->setChecked(false);}
     else if(conf_password=="D3    🟨")
      {  QMessageBox::information(this,"Seat Select","This seat has already been requested\nPlease select other seat");ui->D3_1->setChecked(false);}
    else if(arg1)
     {
        if((int)seat_left.size()==12)
        {
            QMessageBox::warning(this,"Limit","You are maximum allowed to select 4 seats");
        }
        else
        {
            ui->D3_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture388.png);");
            seat_left=ui->label_87->text();
            seat_left+="D3 ";
            ui->label_87->setText(seat_left);
        }
     }
     else {
        ui->D3_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");
        seat_left=ui->label_87->text();
        int i;
        for(i=0;i<seat_left.size();i++)
        {
            if(seat_left[i]=='D' && seat_left[i+1]=='3')
            {
                seat_left.remove(i,3);

            }
        }
        ui->label_87->setText(seat_left);
     }
}

void MainWindow::on_E3_1_stateChanged(int arg1)
{
     conf_password="";
     conf_password=ui->E3_1->text();
     if(conf_password=="E3    🟥")
        {QMessageBox::information(this,"Seat Select","This seat has been booked\nPlease select other seat");ui->E3_1->setChecked(false);}
     else if(conf_password=="E3    🟨")
      {  QMessageBox::information(this,"Seat Select","This seat has already been requested\nPlease select other seat");ui->E3_1->setChecked(false);}
    else if(arg1)
     {
        if((int)seat_left.size()==12)
        {
            QMessageBox::warning(this,"Limit","You are maximum allowed to select 4 seats");
        }
        else
        {
            ui->E3_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture388.png);");
            seat_left=ui->label_87->text();
            seat_left+="E3 ";
            ui->label_87->setText(seat_left);
        }
     }
     else {
        ui->E3_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");
        seat_left=ui->label_87->text();
        int i;
        for(i=0;i<seat_left.size();i++)
        {
            if(seat_left[i]=='E' && seat_left[i+1]=='3')
            {
                seat_left.remove(i,3);

            }
        }
        ui->label_87->setText(seat_left);
     }
}

void MainWindow::on_F3_1_stateChanged(int arg1)
{
     conf_password="";
     conf_password=ui->F3_1->text();
     if(conf_password=="F3    🟥")
        {QMessageBox::information(this,"Seat Select","This seat has been booked\nPlease select other seat");ui->F3_1->setChecked(false);}
     else if(conf_password=="F3    🟨")
      {  QMessageBox::information(this,"Seat Select","This seat has already been requested\nPlease select other seat");ui->F3_1->setChecked(false);}
    else if(arg1)
     {
        if((int)seat_left.size()==12)
        {
            QMessageBox::warning(this,"Limit","You are maximum allowed to select 4 seats");
        }
        else
        {
            ui->F3_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture388.png);");
            seat_left=ui->label_87->text();
            seat_left+="F3 ";
            ui->label_87->setText(seat_left);
        }
     }
     else {
        ui->F3_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");
        seat_left=ui->label_87->text();
        int i;
        for(i=0;i<seat_left.size();i++)
        {
            if(seat_left[i]=='F' && seat_left[i+1]=='3')
            {
                seat_left.remove(i,3);

            }
        }
        ui->label_87->setText(seat_left);
     }
}


void MainWindow::on_G3_1_stateChanged(int arg1)
{
     conf_password="";
     conf_password=ui->G3_1->text();
     if(conf_password=="G3    🟥")
        {QMessageBox::information(this,"Seat Select","This seat has been booked\nPlease select other seat");ui->G3_1->setChecked(false);}
     else if(conf_password=="G3    🟨")
     {   QMessageBox::information(this,"Seat Select","This seat has already been requested\nPlease select other seat");ui->G3_1->setChecked(false);}
    else if(arg1)
     {
        if((int)seat_left.size()==12)
        {
            QMessageBox::warning(this,"Limit","You are maximum allowed to select 4 seats");
        }
        else
        {
            ui->G3_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture388.png);");
            seat_left=ui->label_87->text();
            seat_left+="G3 ";
            ui->label_87->setText(seat_left);
        }
     }
     else {
        ui->G3_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");
        seat_left=ui->label_87->text();
        int i;
        for(i=0;i<seat_left.size();i++)
        {
            if(seat_left[i]=='G' && seat_left[i+1]=='3')
            {
                seat_left.remove(i,3);

            }
        }
        ui->label_87->setText(seat_left);
     }
}


void MainWindow::on_H3_1_stateChanged(int arg1)
{
     conf_password="";
     if(conf_password=="H3    🟥")
        {QMessageBox::information(this,"Seat Select","This seat has been booked\nPlease select other seat");ui->H3_1->setChecked(false);}
     else if(conf_password=="H3    🟨")
      {  QMessageBox::information(this,"Seat Select","This seat has already been requested\nPlease select other seat");ui->H3_1->setChecked(false);}
    else if(arg1)
     {
        if((int)seat_left.size()==12)
        {
            QMessageBox::warning(this,"Limit","You are maximum allowed to select 4 seats");
        }
        else
        {
            ui->H3_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture388.png);");
            seat_left=ui->label_87->text();
            seat_left+="H3 ";
            ui->label_87->setText(seat_left);
        }
     }
     else {
        ui->H3_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");
        seat_left=ui->label_87->text();
        int i;
        for(i=0;i<seat_left.size();i++)
        {
            if(seat_left[i]=='H' && seat_left[i+1]=='3')
            {
                seat_left.remove(i,3);

            }
        }
        ui->label_87->setText(seat_left);
     }
}


void MainWindow::on_I3_1_stateChanged(int arg1)
{
     conf_password="";
     conf_password=ui->I3_1->text();
     if(conf_password=="I3    🟥")
        {QMessageBox::information(this,"Seat Select","This seat has been booked\nPlease select other seat");ui->I3_1->setChecked(false);}
     else if(conf_password=="I3    🟨")
       { QMessageBox::information(this,"Seat Select","This seat has already been requested\nPlease select other seat");ui->I3_1->setChecked(false);}
    else if(arg1)
     {
        if((int)seat_left.size()==12)
        {
            QMessageBox::warning(this,"Limit","You are maximum allowed to select 4 seats");
        }
        else
        {
            ui->I3_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture388.png);");
            seat_left=ui->label_87->text();
            seat_left+="I3 ";
            ui->label_87->setText(seat_left);
        }
     }
     else {
        ui->I3_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");
        seat_left=ui->label_87->text();
        int i;
        for(i=0;i<seat_left.size();i++)
        {
            if(seat_left[i]=='I' && seat_left[i+1]=='3')
            {
                seat_left.remove(i,3);

            }
        }
        ui->label_87->setText(seat_left);
     }
}


void MainWindow::on_A4_1_stateChanged(int arg1)
{
     conf_password="";
     conf_password=ui->A4_1->text();
     if(conf_password=="A4    🟥")
        {QMessageBox::information(this,"Seat Select","This seat has been booked\nPlease select other seat");ui->A4_1->setChecked(false);}
     else if(conf_password=="A4    🟨")
      {  QMessageBox::information(this,"Seat Select","This seat has already been requested\nPlease select other seat");ui->A4_1->setChecked(false);}
    else if(arg1)
     {
        if((int)seat_left.size()==12)
        {
            QMessageBox::warning(this,"Limit","You are maximum allowed to select 4 seats");
        }
        else
        {
            ui->A4_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture388.png);");
            seat_left=ui->label_87->text();
            seat_left+="A4 ";
            ui->label_87->setText(seat_left);
        }
     }
     else {
        ui->A4_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");
        seat_left=ui->label_87->text();
        int i;
        for(i=0;i<seat_left.size();i++)
        {
            if(seat_left[i]=='A' && seat_left[i+1]=='4')
            {
                seat_left.remove(i,3);

            }
        }
        ui->label_87->setText(seat_left);
     }
}


void MainWindow::on_B4_1_stateChanged(int arg1)
{
     conf_password="";
     conf_password=ui->B4_1->text();
     if(conf_password=="B4    🟥")
        {QMessageBox::information(this,"Seat Select","This seat has been booked\nPlease select other seat");ui->B4_1->setChecked(false);}
     else if(conf_password=="B4    🟨")
      {  QMessageBox::information(this,"Seat Select","This seat has already been requested\nPlease select other seat");ui->B4_1->setChecked(false);}
    else if(arg1)
     {
        if((int)seat_left.size()==12)
        {
            QMessageBox::warning(this,"Limit","You are maximum allowed to select 4 seats");
        }
        else
        {
            ui->B4_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture388.png);");
            seat_left=ui->label_87->text();
            seat_left+="B4 ";
            ui->label_87->setText(seat_left);
        }
     }
     else {
       ui->B4_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");
        seat_left=ui->label_87->text();
        int i;
        for(i=0;i<seat_left.size();i++)
        {
            if(seat_left[i]=='B' && seat_left[i+1]=='4')
            {
                seat_left.remove(i,3);

            }
        }
        ui->label_87->setText(seat_left);
     }
}


void MainWindow::on_C4_1_stateChanged(int arg1)
{
     conf_password="";
     conf_password=ui->C4_1->text();
     if(conf_password=="C4    🟥")
        {QMessageBox::information(this,"Seat Select","This seat has been booked\nPlease select other seat");ui->C4_1->setChecked(false);}
     else if(conf_password=="C4    🟨")
     {   QMessageBox::information(this,"Seat Select","This seat has already been requested\nPlease select other seat");ui->C4_1->setChecked(false);}
    else if(arg1)
     {
        if((int)seat_left.size()==12)
        {
            QMessageBox::warning(this,"Limit","You are maximum allowed to select 4 seats");
        }
        else
        {
            ui->C4_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture388.png);");
            seat_left=ui->label_87->text();
            seat_left+="C4 ";
            ui->label_87->setText(seat_left);
        }
     }
     else {
        ui->C4_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");
        seat_left=ui->label_87->text();
        int i;
        for(i=0;i<seat_left.size();i++)
        {
            if(seat_left[i]=='C' && seat_left[i+1]=='4')
            {
                seat_left.remove(i,3);

            }
        }
        ui->label_87->setText(seat_left);
     }
}


void MainWindow::on_D4_1_stateChanged(int arg1)
{
     conf_password="";
     conf_password=ui->D4_1->text();
     if(conf_password=="D4    🟥")
        {QMessageBox::information(this,"Seat Select","This seat has been booked\nPlease select other seat");ui->D4_1->setChecked(false);}
     else if(conf_password=="D4    🟨")
      {  QMessageBox::information(this,"Seat Select","This seat has already been requested\nPlease select other seat");ui->D4_1->setChecked(false);}
    else if(arg1)
     {
        if((int)seat_left.size()==12)
        {
            QMessageBox::warning(this,"Limit","You are maximum allowed to select 4 seats");
        }
        else
        {
            ui->D4_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture388.png);");
            seat_left=ui->label_87->text();
            seat_left+="D4 ";
            ui->label_87->setText(seat_left);
        }
     }
     else {
        ui->D4_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");
        seat_left=ui->label_87->text();
        int i;
        for(i=0;i<seat_left.size();i++)
        {
            if(seat_left[i]=='D' && seat_left[i+1]=='4')
            {
                seat_left.remove(i,3);

            }
        }
        ui->label_87->setText(seat_left);
     }
}


void MainWindow::on_E4_1_stateChanged(int arg1)
{
     conf_password="";
     conf_password=ui->E4_1->text();
     if(conf_password=="E4    🟥")
        {QMessageBox::information(this,"Seat Select","This seat has been booked\nPlease select other seat");ui->E4_1->setChecked(false);}
     else if(conf_password=="E4    🟨")
       { QMessageBox::information(this,"Seat Select","This seat has already been requested\nPlease select other seat");ui->E4_1->setChecked(false);}
    else if(arg1)
     {
        if((int)seat_left.size()==12)
        {
            QMessageBox::warning(this,"Limit","You are maximum allowed to select 4 seats");
        }
        else
        {
            ui->E4_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture388.png);");
            seat_left=ui->label_87->text();
            seat_left+="E4 ";
            ui->label_87->setText(seat_left);
        }
     }
     else {
        ui->E4_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");
        seat_left=ui->label_87->text();
        int i;
        for(i=0;i<seat_left.size();i++)
        {
            if(seat_left[i]=='E' && seat_left[i+1]=='4')
            {
                seat_left.remove(i,3);

            }
        }
        ui->label_87->setText(seat_left);
     }
}


void MainWindow::on_F4_1_stateChanged(int arg1)
{
     conf_password="";
     conf_password=ui->F4_1->text();
     if(conf_password=="F4    🟥")
        {QMessageBox::information(this,"Seat Select","This seat has been booked\nPlease select other seat");ui->F4_1->setChecked(false);}
     else if(conf_password=="F4    🟨")
      {  QMessageBox::information(this,"Seat Select","This seat has already been requested\nPlease select other seat");ui->F4_1->setChecked(false);}
    else if(arg1)
     {
        if((int)seat_left.size()==12)
        {
            QMessageBox::warning(this,"Limit","You are maximum allowed to select 4 seats");
        }
        else
        {
            ui->F4_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture388.png);");
            seat_left=ui->label_87->text();
            seat_left+="F4 ";
            ui->label_87->setText(seat_left);
        }
     }
     else {
        ui->F4_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");
        seat_left=ui->label_87->text();
        int i;
        for(i=0;i<seat_left.size();i++)
        {
            if(seat_left[i]=='F' && seat_left[i+1]=='4')
            {
                seat_left.remove(i,3);

            }
        }
        ui->label_87->setText(seat_left);
     }
}


void MainWindow::on_G4_1_stateChanged(int arg1)
{
     conf_password="";
     conf_password=ui->G4_1->text();
     if(conf_password=="G4    🟥")
        {QMessageBox::information(this,"Seat Select","This seat has been booked\nPlease select other seat");ui->G4_1->setChecked(false);}
     else if(conf_password=="G4    🟨")
      {  QMessageBox::information(this,"Seat Select","This seat has already been requested\nPlease select other seat");ui->G4_1->setChecked(false);}
    else if(arg1)
     {
        if((int)seat_left.size()==12)
        {
            QMessageBox::warning(this,"Limit","You are maximum allowed to select 4 seats");
        }
        else
        {
            ui->G4_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture388.png);");
            seat_left=ui->label_87->text();
            seat_left+="G4 ";
            ui->label_87->setText(seat_left);
        }
     }
     else {
        ui->G4_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");
        seat_left=ui->label_87->text();
        int i;
        for(i=0;i<seat_left.size();i++)
        {
            if(seat_left[i]=='G' && seat_left[i+1]=='4')
            {
                seat_left.remove(i,3);

            }
        }
        ui->label_87->setText(seat_left);
     }
}


void MainWindow::on_H4_1_stateChanged(int arg1)
{
     conf_password="";
     conf_password=ui->H4_1->text();
     if(conf_password=="H4    🟥")
        {QMessageBox::information(this,"Seat Select","This seat has been booked\nPlease select other seat");ui->H4_1->setChecked(false);}
     else if(conf_password=="H4    🟨")
       { QMessageBox::information(this,"Seat Select","This seat has already been requested\nPlease select other seat");ui->H4_1->setChecked(false);}
    else if(arg1)
     {
        if((int)seat_left.size()==12)
        {
            QMessageBox::warning(this,"Limit","You are maximum allowed to select 4 seats");
        }
        else
        {
            ui->H4_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture388.png);");
            seat_left=ui->label_87->text();
            seat_left+="H4 ";
            ui->label_87->setText(seat_left);
        }
     }
     else {
        ui->H4_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");
        seat_left=ui->label_87->text();
        int i;
        for(i=0;i<seat_left.size();i++)
        {
            if(seat_left[i]=='H' && seat_left[i+1]=='4')
            {
                seat_left.remove(i,3);

            }
        }
        ui->label_87->setText(seat_left);
     }
}


void MainWindow::on_I4_1_stateChanged(int arg1)
{
     conf_password="";
     conf_password=ui->I4_1->text();
     if(conf_password=="I4    🟥")
        {QMessageBox::information(this,"Seat Select","This seat has been booked\nPlease select other seat");ui->I4_1->setChecked(false);}
     else if(conf_password=="I4    🟨")
      {  QMessageBox::information(this,"Seat Select","This seat has already been requested\nPlease select other seat");ui->I4_1->setChecked(false);}
    else if(arg1)
     {
        if((int)seat_left.size()==12)
        {
            QMessageBox::warning(this,"Limit","You are maximum allowed to select 4 seats");
        }
        else
        {
            ui->I4_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture388.png);");
            seat_left=ui->label_87->text();
            seat_left+="I4 ";
            ui->label_87->setText(seat_left);
        }
     }
     else {
       ui->I4_1->setStyleSheet("image: url(:/new/prefix1/ImageC/Picture32.png);");
        seat_left=ui->label_87->text();
        int i;
        for(i=0;i<seat_left.size();i++)
        {
            if(seat_left[i]=='I' && seat_left[i+1]=='4')
            {
                seat_left.remove(i,3);

            }
        }
        ui->label_87->setText(seat_left);
     }
}


void MainWindow::on_Edit_profile_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
    email=ui->label_103->text();
    QSqlQuery query1;
    query1.exec("SELECT * FROM user WHERE email = '"+email+"'");
    if(query1.next()) {
        name=query1.value(0).toString();
        ui->Name_input_update->setText(name);
        mobile=query1.value(3).toString();
        ui->Mobile_input_update->setText(mobile);
        birth=query1.value(5).toString();
        ui->Birth_input_update->setText(birth);
        address=query1.value(6).toString();
        ui->Address_input_update->setText(address);
    }
}

void MainWindow::on_Update_button_clicked()
{
    name=ui->Name_input_update->text();
    email=ui->label_103->text();
    mobile=ui->Mobile_input_update->text();
    birth=ui->Birth_input_update->text();
    address=ui->Address_input_update->text();
    password=ui->Password_input_update->text();
    QSqlQuery query1;
    query1.exec("SELECT * FROM user WHERE email = '"+email+"' AND password='"+password+"' ");
    if(query1.next())
    {
        query1.exec("UPDATE user SET name='"+name+"', mobile='"+mobile+"', date_of_birth='"+birth+"', address='"+address+"' WHERE email = '"+email+"' ");
        QMessageBox::information(this,"Update Profile","Updated Profile Successfully");
        ui->stackedWidget->setCurrentIndex(6);
        ui->Name_input_update->clear();
        ui->Mobile_input_update->clear();
        ui->Birth_input_update->clear();
        ui->Address_input_update->clear();
        ui->label_9->setText(name);
        ui->label_101->setText(name);
        ui->label_103->setText(email);
        ui->label_105->setText(mobile);
        ui->label_107->setText(birth);
        ui->label_109->setText(address);
    }
    else QMessageBox::warning(this,"Error","Wrong Password");
}

void MainWindow::on_Admin_main_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}


void MainWindow::on_Login_button_admin_clicked()
{
    email=ui->Email_input_login_admin->text();
    password=ui->Password_input_login_admin->text();
    if(email=="")
        QMessageBox::warning(this,"Login","Email field can't be empty");
    else if(password=="")
        QMessageBox::warning(this,"Login","Password field can't be empty");
    else{
    QSqlQuery query1;
    query1.exec("SELECT * FROM admin WHERE email = '"+email+"' AND password='"+password+"' ");
    if(query1.next())
    {
        QMessageBox::information(this,"Login","Login Successfully");
        ui->stackedWidget->setCurrentIndex(10);
        QSqlQueryModel *modal=new QSqlQueryModel();
        QSqlQuery* qry=new QSqlQuery(database);
        qry->exec("select * from admin_request");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView->setModel(modal);
        ///qDebug()<< modal->rowCount();
        ui->label_168->setText(query1.value(0).toString());
        ui->label_169->setText(query1.value(1).toString());
        ui->label_170->setText(query1.value(3).toString());
        QPixmap pix(query1.value(4).toString());
        int w=ui->label_151->width();
        int h=ui->label_151->height();
        ui->label_151->setPixmap(pix.scaled(w,h,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));  /// image of admin
    }
    else {
        QMessageBox::warning(this,"Login","Wrong Email & Password");
        /// QMessageBox::critical(this,"Login","Wrong Email & Password");
        }
    }
}


void MainWindow::on_Admin_back_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->Email_input_login_admin->clear();
//    ui->pass
}


void MainWindow::on_Proceed_to_payment_button_clicked()
{
    count=0;
    seat=ui->label_87->text();
    for(int i=0;i<seat.size();i+=3)
    {
        count++;
    }
    if(count==0)
        QMessageBox::about(this,"Select Seat","Please select a seat");
    else {
    ui->stackedWidget->setCurrentIndex(9);
    from=ui->label_14->text();
   /// conf_password=ui->label_21->text();
    //conf_password.remove(0,6);
    ui->label_136->setText("1500");
    ui->label_141->setText("X");
    ui->label_137->setText("69 X");
    ui->label_138->setText("20 X");
    to=ui->label_16->text();
    ui->label_121->setText(from);
    ui->label_124->setText(to);
    ui->label_142->setText(QString::number(count));
    ui->label_143->setText(QString::number(count));
    ui->label_144->setText(QString::number(count));
    total=((1500+20+69)*count)-discount;
    ui->label_147->setText(QString::number(total));
    ui->label_139->clear();
    ui->label_139->setText(QString::number(discount));
  }
}
void MainWindow::on_hello_clicked()
{
  if(ui->A1_1->isChecked())
    ui->A1_1->setChecked(false);
  if(ui->A2_1->isChecked())
    ui->A2_1->setChecked(false);
  if(ui->A3_1->isChecked())
    ui->A3_1->setChecked(false);
  if(ui->A4_1->isChecked())
    ui->A4_1->setChecked(false);
  if(ui->B1_1->isChecked())
    ui->B1_1->setChecked(false);
  if(ui->B2_1->isChecked())
    ui->B2_1->setChecked(false);
  if(ui->B3_1->isChecked())
    ui->B3_1->setChecked(false);
  if(ui->B4_1->isChecked())
    ui->B4_1->setChecked(false);
  if(ui->C1_1->isChecked())
    ui->C1_1->setChecked(false);
  if(ui->C2_1->isChecked())
    ui->C2_1->setChecked(false);
  if(ui->C3_1->isChecked())
    ui->C3_1->setChecked(false);
  if(ui->C4_1->isChecked())
    ui->C4_1->setChecked(false);
  if(ui->D1_1->isChecked())
    ui->D1_1->setChecked(false);
  if(ui->D2_1->isChecked())
    ui->D2_1->setChecked(false);
  if(ui->D3_1->isChecked())
    ui->D3_1->setChecked(false);
  if(ui->D4_1->isChecked())
    ui->D4_1->setChecked(false);
  if(ui->E1_1->isChecked())
    ui->E1_1->setChecked(false);
  if(ui->E2_1->isChecked())
    ui->E2_1->setChecked(false);
  if(ui->E3_1->isChecked())
    ui->E3_1->setChecked(false);
  if(ui->E4_1->isChecked())
    ui->E4_1->setChecked(false);
  if(ui->F1_1->isChecked())
    ui->F1_1->setChecked(false);
  if(ui->F2_1->isChecked())
    ui->F2_1->setChecked(false);
  if(ui->F3_1->isChecked())
    ui->F3_1->setChecked(false);
  if(ui->F4_1->isChecked())
    ui->F4_1->setChecked(false);
  if(ui->G1_1->isChecked())
    ui->G1_1->setChecked(false);
  if(ui->G2_1->isChecked())
    ui->G2_1->setChecked(false);
  if(ui->G3_1->isChecked())
    ui->G3_1->setChecked(false);
  if(ui->G4_1->isChecked())
    ui->G4_1->setChecked(false);
  if(ui->H1_1->isChecked())
    ui->H1_1->setChecked(false);
  if(ui->H2_1->isChecked())
    ui->H2_1->setChecked(false);
  if(ui->H3_1->isChecked())
    ui->H3_1->setChecked(false);
  if(ui->H4_1->isChecked())
    ui->H4_1->setChecked(false);
  if(ui->I1_1->isChecked())
    ui->I1_1->setChecked(false);
  if(ui->I2_1->isChecked())
    ui->I2_1->setChecked(false);
  if(ui->I3_1->isChecked())
    ui->I3_1->setChecked(false);
  if(ui->I4_1->isChecked())
    ui->I4_1->setChecked(false);
}

void MainWindow::on_Seat_select_back_button_clicked()
{
  ui->stackedWidget->setCurrentIndex(4);
  on_hello_clicked();
}

void MainWindow::on_Payment_page_back_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}


void MainWindow::on_Apply_button_clicked()
{
    coupon=ui->Coupon_code_input->text();
    if(coupon=="Hello World")
    {
        discount=60;
        on_Proceed_to_payment_button_clicked();
    }
    else QMessageBox::warning(this,"Coupon Code","Wrong Discount/Coupon Code");
}

void MainWindow::on_Pay_button_clicked()
{
    ui->label_136->clear();
    ui->label_142->clear();
    ui->label_143->clear();
    ui->label_144->clear();
    ui->label_147->clear();
    ui->label_139->clear();
    ui->label_139->clear();
    ui->label_141->clear();
    ui->label_137->clear();
    ui->label_138->clear();
    name=ui->label_101->text();
    email=ui->label_103->text();
    ui->stackedWidget->setCurrentIndex(3);
    QMessageBox::information(this,"Payment","Amount Paid Successfully\nYour Request for seat has been sent");
    conf_password="";
    Class=ui->Class_combobox->currentText();
    date=ui->Date_combobox->currentText();
    from=ui->label_121->text();
    to=ui->label_124->text();
    QSqlQuery query1;
    count=0;
    query1.exec("SELECT * FROM admin_request");
    while(query1.next())
        count++;
    for(int i=0;i<seat.size();i+=3)
    {
        conf_password+=seat[i];count++;
        conf_password+=seat[i+1];
        query1.exec("SELECT * FROM BUS WHERE name = '"+conf_password+"'");
        if(query1.next())
        {
            query1.exec("UPDATE bus SET book='1', email='"+email+"' WHERE name = '"+conf_password+"' ");
            query1.exec("INSERT INTO admin_request (NAME,EMAIL,SEAT,BUS,TIME,CLASS,DATE,F,T) VALUES ('"+name+"','"+email+"','"+conf_password+"','Shohagh Paribahan','11:00 PM - 06:00 AM','"+Class+"','"+date+"','"+from+"','"+to+"') ");
        }
        conf_password="";
    }
    ui->label_87->clear();
    count=0;
    seat_left="";
    on_hello_clicked();
}

void MainWindow::on_Profile_update_back_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_My_ticket_back_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->Cancel_request_seat->clear();
    ui->Cancel_request_bus->clear();
}

void MainWindow::on_My_ticket_back_button_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
    ui->Cancel_ticket_seat->clear();
    ui->Cancel_ticket_bus->clear();
}

void MainWindow::on_Cancel_request_button_clicked()
{
    name=ui->label_9->text();
    cancel=ui->Cancel_request_seat->text();
    bus=ui->Cancel_request_bus->text();
    QSqlQuery query1;
    query1.exec("SELECT * FROM admin_request WHERE SEAT=='"+cancel+"' AND BUS=='"+bus+"' ");
    if(query1.next())
    {
        query1.exec("DELETE FROM admin_request WHERE SEAT=='"+cancel+"' AND BUS=='"+bus+"' ");
        ui->stackedWidget->setCurrentIndex(10);
        ui->stackedWidget->setCurrentIndex(11);
        QSqlQueryModel *modal=new QSqlQueryModel();
        QSqlQuery* qry=new QSqlQuery(database);
        qry->exec("select * from admin_request");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView_2->setModel(modal);
        QMessageBox::about(this,"Cancel Request","Your request for ticket has been successfully cancelled");
        QSqlQuery query2;
        query2.exec("SELECT * FROM bus WHERE name = '"+cancel+"'");
        if(query2.next())
            query2.exec("UPDATE bus SET book='0' WHERE name = '"+cancel+"' ");
    }
    else QMessageBox::warning(this,"Cancel Tickets","Wrong Seat no & Bus name");
}

void MainWindow::on_My_ticket_next_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
    ui->Cancel_request_seat->clear();
    ui->Cancel_request_bus->clear();
    QSqlQueryModel *modal=new QSqlQueryModel();
    QSqlQuery* qry=new QSqlQuery(database);
    qry->exec("select * from confirmed_tickets");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView_3->setModel(modal);
}

void MainWindow::on_Admin_next_button_2_clicked()
{
    ui->Accept_request_bus_input->clear();
    ui->Accept_request_seat_input->clear();
    ui->stackedWidget->setCurrentIndex(15);
    QSqlQueryModel *modal=new QSqlQueryModel();
    QSqlQuery* qry=new QSqlQuery(database);
    qry->prepare("select * from cancel_ticket");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView_5->setModel(modal);
}

void MainWindow::on_Admin_profile_back_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);
    ui->Admin_add_name_input->clear();
    ui->Admin_add_email_input->clear();
    ui->Admin_add_mobile_input->clear();
}


void MainWindow::on_Admin_logout_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->Admin_add_name_input->clear();
    ui->Admin_add_email_input->clear();
    ui->Admin_add_mobile_input->clear();
}


void MainWindow::on_Request_reject_button_clicked()
{
    cancel=ui->Accept_request_seat_input->text();
    bus=ui->Accept_request_bus_input->text();
    QSqlQuery query1;
    query1.exec("SELECT * FROM admin_request WHERE SEAT=='"+cancel+"' AND BUS=='"+bus+"' ");
    if(query1.next())
    {
        query1.exec("DELETE FROM admin_request WHERE SEAT=='"+cancel+"' AND BUS=='"+bus+"' ");
        ui->stackedWidget->setCurrentIndex(13);
        ui->stackedWidget->setCurrentIndex(10);
        QSqlQueryModel *modal=new QSqlQueryModel();
        QSqlQuery* qry=new QSqlQuery(database);
        qry->exec("select * from admin_request");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView->setModel(modal);
        ///QMessageBox::about(this,"Cancel Request","Your request for ticket has been successfully cancelled");
        QSqlQuery query2;
        query2.exec("SELECT * FROM bus WHERE name = '"+cancel+"'");
        if(query2.next())
            query2.exec("UPDATE bus SET book='0' WHERE name = '"+cancel+"' ");
    }
    else QMessageBox::warning(this,"Reject Request","Wrong Seat or Bus No");
}


void MainWindow::on_Request_accept_button_clicked()
{
    cancel=ui->Accept_request_seat_input->text();
    bus=ui->Accept_request_bus_input->text();
    QSqlQuery query1;
    query1.exec("SELECT * FROM admin_request WHERE SEAT=='"+cancel+"' AND BUS=='"+bus+"' ");
    if(query1.next())
    {
        QSqlQuery query2;
        query2.exec("INSERT INTO confirmed_tickets (NAME,EMAIL,SEAT,BUS,TIME,CLASS,DATE,F,T) VALUES ('"+query1.value(0).toString()+"','"+query1.value(1).toString()+"','"+query1.value(2).toString()+"','"+query1.value(3).toString()+"','"+query1.value(4).toString()+"','"+query1.value(5).toString()+"','"+query1.value(6).toString()+"','"+query1.value(7).toString()+"','"+query1.value(8).toString()+"' )");
        query1.exec("DELETE FROM admin_request WHERE SEAT=='"+cancel+"' AND BUS=='"+bus+"' ");
        ui->stackedWidget->setCurrentIndex(13);
        ui->stackedWidget->setCurrentIndex(10);
        QSqlQueryModel *modal=new QSqlQueryModel();
        QSqlQuery* qry=new QSqlQuery(database);
        qry->exec("select * from admin_request");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView->setModel(modal);
        ///QMessageBox::about(this,"Cancel Request","Your request for ticket has been successfully cancelled");
        query2.exec("SELECT * FROM bus WHERE name = '"+cancel+"'");
        if(query2.next())
            query2.exec("UPDATE bus SET book='2' WHERE name = '"+cancel+"' ");
    }
    else QMessageBox::warning(this,"Accept Request","Wrong Seat or Bus No");
}


void MainWindow::on_Admin_add_button_clicked()
{
    name=ui->Admin_add_name_input->text();
    email=ui->Admin_add_email_input->text();
    mobile=ui->Admin_add_mobile_input->text();
    password=ui->Admin_add_password_input->text();
    imagepath="E:/project pic/nopic.jpg";
    QSqlQuery query1;
    query1.exec("SELECT * FROM admin WHERE email = '"+email+"' ");
    if(name=="")
        QMessageBox::warning(this,"Add Admin","Name field can't be empty");
    else if(email=="")
        QMessageBox::warning(this,"Add Admin","Email field can't be empty");
    else if(mobile=="")
        QMessageBox::warning(this,"Add Admin","Mobile field can't be empty");
    else if(password=="")
        QMessageBox::warning(this,"Add Admin","Password field can't be empty");
    else if(query1.next()) {
        QMessageBox::about(this,"Add Admin","This email is already taken");
    }
    else {
        query1.exec("INSERT INTO admin (name,email,password,contact,image) VALUES ('"+name+"','"+email+"','"+password+"','"+mobile+"','"+imagepath+"')");
        ui->stackedWidget->setCurrentIndex(10);
        QSqlQueryModel *modal=new QSqlQueryModel();
        QSqlQuery* qry=new QSqlQuery(database);
        qry->prepare("select name,email,contact from admin");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView_4->setModel(modal);
        ui->stackedWidget->setCurrentIndex(13);
        QMessageBox::information(this,"Add Admin","Successfully Added Admin");
    }
    ui->Admin_add_name_input->clear();
    ui->Admin_add_email_input->clear();
    ui->Admin_add_mobile_input->clear();
    ui->Admin_add_password_input->clear();
}


void MainWindow::on_Admin_remove_button_clicked()
{
    name=ui->Admin_add_name_input->text();
    email=ui->Admin_add_email_input->text();
    mobile=ui->Admin_add_mobile_input->text();
    QSqlQuery query1;
    query1.exec("SELECT * FROM admin WHERE name = '"+name+"' AND email='"+email+"' ");
    if(query1.next())
    {
        query1.exec("DELETE FROM admin WHERE email = '"+email+"' ");
        ui->stackedWidget->setCurrentIndex(10);
        QSqlQueryModel *modal=new QSqlQueryModel();
        QSqlQuery* qry=new QSqlQuery(database);
        qry->prepare("select name,email,contact from admin");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView_4->setModel(modal);
        ui->stackedWidget->setCurrentIndex(13);
        QMessageBox::information(this,"Remove Admin","Successfully Removed Admin");
    }
    else {
        QMessageBox::warning(this,"Remove Admin","Wrong Name & Email");
    }
    ui->Admin_add_name_input->clear();
    ui->Admin_add_email_input->clear();
    ui->Admin_add_mobile_input->clear();
    ui->Admin_add_password_input->clear();
}


void MainWindow::on_Change_photo_button_2_clicked()
{
    email=ui->label_169->text();
    imagepath = QFileDialog::getOpenFileName(this,tr("Open Image"),"",tr("JPEG (*.jpg *.jpeg);;PNG (*png)")); //image select
    QPixmap picture(imagepath);
    //QPixmap picture("c:/Users/ProgrammingKnowledge/Pictures?qt_pic/login-icon.png); -> direct select
    int w=ui->label_151->width();
    int h=ui->label_151->height();
    ui->label_151->setPixmap(picture.scaled(w,h,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));  //Qt::KeepAspectRatio
    QSqlQuery query1;
    query1.exec("UPDATE admin SET image='"+imagepath+"' WHERE email = '"+email+"'");
    query1.next();
    QMessageBox::information(this,"Change Photo","Successfully Updated Photo");
}

void MainWindow::on_Cancel_ticket_button_clicked()
{
    name=ui->label_9->text();
    cancel=ui->Cancel_ticket_seat->text();
    bus=ui->Cancel_ticket_bus->text();
    QSqlQuery query1;
    query1.exec("SELECT * FROM confirmed_tickets WHERE SEAT=='"+cancel+"' AND BUS=='"+bus+"' ");
    if(query1.next())
    {
        QSqlQuery query2;
        query2.exec("SELECT * FROM cancel_ticket WHERE SEAT=='"+cancel+"' AND BUS=='"+bus+"' ");
        if(query2.next())
            QMessageBox::about(this,"Cancel Ticket","Your request has already been sent");
        else {
            query2.exec("INSERT INTO cancel_ticket (NAME,EMAIL,SEAT,BUS,TIME,CLASS,DATE,F,T) VALUES ('"+query1.value(0).toString()+"','"+query1.value(1).toString()+"','"+query1.value(2).toString()+"','"+query1.value(3).toString()+"','"+query1.value(4).toString()+"','"+query1.value(5).toString()+"','"+query1.value(6).toString()+"','"+query1.value(7).toString()+"','"+query1.value(8).toString()+"' )");
            QMessageBox::about(this,"Cancel Ticket","Your request to cancel ticket has been sent");
        }
    }
    else QMessageBox::warning(this,"Cancel Tickets","Wrong Seat No & Bus Name");
}

void MainWindow::on_Print_ticket_button_clicked()
{
    cancel=ui->Cancel_ticket_seat->text();
    bus=ui->Cancel_ticket_bus->text();
    ui->label_58->setText(bus);
    ui->label_59->setText(cancel);
    if(cancel=="")
        QMessageBox::warning(this,"Print Ticket","Seat no field can't be empty");
    else if(bus=="")
        QMessageBox::warning(this,"Print Ticket","Bus name field can't be empty");
    else {
    ui->stackedWidget->setCurrentIndex(14);
    QSqlQuery query1;
    query1.exec("SELECT * FROM confirmed_tickets WHERE SEAT=='"+cancel+"' AND BUS=='"+bus+"' ");
    if(query1.next())
    {
        ui->label_78->setText(query1.value(6).toString());
        ui->label_75->setText(query1.value(7).toString());
        ui->label_76->setText(query1.value(8).toString());
        ui->label_77->setText(query1.value(4).toString());
    }
    }
}


void MainWindow::on_Cancel_reject_button_clicked()
{
    cancel=ui->Admin_cancel_ticket_seat_input->text();
    bus=ui->Admin_cancel_ticket_bus_input->text();
    QSqlQuery query1;
    query1.exec("SELECT * FROM cancel_ticket WHERE SEAT=='"+cancel+"' AND BUS=='"+bus+"' ");
    if(query1.next())
    {
        query1.exec("DELETE FROM cancel_ticket WHERE SEAT=='"+cancel+"' AND BUS=='"+bus+"' ");
        QSqlQueryModel *modal=new QSqlQueryModel();
        QSqlQuery* qry=new QSqlQuery(database);
        qry->exec("select * from cancel_ticket");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView_5->setModel(modal);
        QMessageBox::about(this,"Cancel Ticket","The request has been successfully rejected");
    }
    else QMessageBox::warning(this,"Cancel Ticket","Wrong Seat or Bus No");
}


void MainWindow::on_Admin_profile_back_button_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
    ui->Admin_cancel_ticket_seat_input->clear();
    ui->Admin_cancel_ticket_bus_input->clear();
}


void MainWindow::on_Admin_next_button_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
    QSqlQueryModel *modal=new QSqlQueryModel();
    QSqlQuery* qry=new QSqlQuery(database);
    qry->prepare("select name,email,contact from admin");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView_4->setModel(modal);
    ui->Admin_cancel_ticket_seat_input->clear();
    ui->Admin_cancel_ticket_bus_input->clear();
}


void MainWindow::on_Cancel_accept_button_clicked()
{
    cancel=ui->Admin_cancel_ticket_seat_input->text();
    bus=ui->Admin_cancel_ticket_bus_input->text();
    QSqlQuery query1;
    query1.exec("SELECT * FROM cancel_ticket WHERE SEAT=='"+cancel+"' AND BUS=='"+bus+"' ");
    if(query1.next())
    {
        query1.exec("DELETE FROM cancel_ticket WHERE SEAT=='"+cancel+"' AND BUS=='"+bus+"' ");
        QSqlQuery query2;
        query2.exec("SELECT * FROM confirmed_tickets WHERE SEAT=='"+cancel+"' AND BUS=='"+bus+"' ");
        if(query2.next())
        {
            query2.exec("DELETE FROM confirmed_tickets WHERE SEAT=='"+cancel+"' AND BUS=='"+bus+"' ");
            query2.exec("SELECT * FROM bus WHERE name = '"+cancel+"'");
            if(query2.next())
                query2.exec("UPDATE bus SET book='0' WHERE name = '"+cancel+"' ");
        }
        QSqlQueryModel *modal=new QSqlQueryModel();
        QSqlQuery* qry=new QSqlQuery(database);
        qry->exec("select * from cancel_ticket");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView_5->setModel(modal);
        QMessageBox::about(this,"Cancel Ticket","The request has been successfully accepted");
    }
    else QMessageBox::warning(this,"Cancel Ticket","Wrong Seat or Bus No");
}


void MainWindow::on_Download_ticket_button_clicked()
{
    QRect capture(120,120,571,271);
    QPixmap screenshot= grab(capture);
    imagepath = QFileDialog::getSaveFileName(this,"Save Screenshot","", "Image (*.png);;All Files (*.*) ");
    screenshot.save(imagepath);
}


void MainWindow::on_Print_page_back_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}

