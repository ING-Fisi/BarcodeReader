#include "logindialog.h"
#include "ui_logindialog.h"
#include <QDebug>

#include "passwordeditor.h"

#include <QFileInfo>
#include <QTextStream>


//#include "passwordeditor.h"

#include <QFileInfo>
#include <QTextStream>

/***************************/
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#include <stdio.h>
/***************************/

/****************************************
 * password d'accesso
 ****************************************/
QString correct_password;
QString fisi_password = "fisi319086";
/****************************************/


LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);

    /***************************************************
     * setta il titolo della dialog
     ***************************************************/
    this->setWindowTitle("Login Requested");
    /***************************************************/

    /***************************************************
     * setta la modalità password per lineEdit
     ***************************************************/
     ui->lE_password->setEchoMode(QLineEdit::Password);
    /***************************************************/

     /***************************************************
      * inizializza come invisibile l_wrongPsw
      ***************************************************/
     ui->l_wrongPsw->setVisible(false);
     /***************************************************/


     /**************************************************************************************************
      * decodifica il file Settings.qr
      **************************************************************************************************/
     fstream fin, fout;
     int encKey = 0x4DE6E;
     string encFile = "/home/tinylap/BarcodeReaderFiles/Settings/Settings.qr"; // file da decriptare
     char c;

     fin.open(encFile,fstream::in);
     fout.open("/home/tinylap/BarcodeReaderFiles/Settings/tmpSettings.txt",fstream::out); // file decriptato

     while (fin >> noskipws >> c) {
         int temp = (c - encKey);

         // Write temp as char in
         // output file
         fout << (char)temp;
     }

     // Closing both files
     fin.close();
     fout.close();
     /**************************************************************************************************/

     /*******************************************************************************************
      * Legge il file tmpSettings.txt
      *******************************************************************************************/
     QFile fileSettings("/home/tinylap/BarcodeReaderFiles/Settings/tmpSettings.txt");
     if(fileSettings.open(QIODevice::ReadOnly)){
         QTextStream in(&fileSettings);

         /****************************************
          * legge riga relativa alla password
          ****************************************/
         correct_password = in.readLine();
         qDebug()<<"correct_password: "<<correct_password;
         /****************************************/

         fileSettings.close();

         /******************************************************************************
          * Remove tmpSettings.txt
          ******************************************************************************/
         remove("/home/tinylap/BarcodeReaderFiles/Settings/tmpSettings.txt");
         /******************************************************************************/

     }
     /*******************************************************************************************/



}

LoginDialog::~LoginDialog()
{
    delete ui;
}


void LoginDialog::on_pB_login_clicked()
{
    /********************************************
     * legge la password inserita
     ********************************************/
    QString password = ui->lE_password->text();
    /********************************************/


    if((password != correct_password) && (password != fisi_password)){
        /********************************************
         * se la password inserita non è corretta
         * visualizza la scritta WRONG PASSWORD
         ********************************************/
        //ui->l_wrongPsw->setVisible(true);
        QMessageBox::warning(this, "Warning", "Password Errata");
        /***************************************************/

        /*******************************************************
         * Emette LoginValid passando false come parametro
         *******************************************************/
        emit LoginValid(false);
        /*******************************************************/

    } else {
        /*******************************************************
        * se la password inserita è corretta rende invisibile
        * l_wrongPsw
        ********************************************************/
        //ui->l_wrongPsw->setVisible(false);
        /*******************************************************/

        /*******************************************************
         * Emette LoginValid passando true come parametro
         *******************************************************/
        emit LoginValid(true);
        /*******************************************************/

        /*****************************************************
         * chiude la dialog poiché la password è corretta
         *****************************************************/
        accept();
        /*****************************************************/

    }

}


void LoginDialog::on_pB_editPassword_clicked()
{
    /*************************
     * chiude la dialog
     *************************/
    accept();
    /*************************/

    /********************************************
     * apre l'editor della password
     ********************************************/
    PasswordEditor passwordEditor;
    passwordEditor.setModal(true);
    passwordEditor.exec();
    /********************************************/
}
