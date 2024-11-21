#include "passwordeditor.h"
#include "ui_passwordeditor.h"

#include <QFileInfo>
#include <QTextStream>

#include <QMessageBox>

#include <QDebug>


/***************************/
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#include <stdio.h>
/***************************/

/*****************************************
 * password d'accesso fisitron
 *****************************************/
QString fisi_passwordTmp = "fisi319086";
/*****************************************/

/****************************************
 * nuova password d'accesso
 ****************************************/
QString new_password;
/****************************************/

/****************************************************************************
 * variabile contenuta nel file Settings.txt
 ****************************************************************************/
QString correct_passwordTmp;
/****************************************************************************/


PasswordEditor::PasswordEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PasswordEditor)
{
    ui->setupUi(this);
    this->setWindowTitle("Password Editor");


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


    /**************************************************************************************************
     * legge il file tmpSettings.txt
     **************************************************************************************************/
    QFile fileSettings("/home/tinylap/BarcodeReaderFiles/Settings/tmpSettings.txt");
    if(fileSettings.open(QIODevice::ReadOnly)){
        QTextStream in(&fileSettings);

        /****************************************
         * legge riga relativa alla password
         ****************************************/
        correct_passwordTmp = in.readLine();
        /****************************************/

        fileSettings.close();

        /******************************************************************************
         * Remove tmpSettings.txt
         ******************************************************************************/
        remove("/home/tinylap/BarcodeReaderFiles/Settings/tmpSettings.txt");
        /******************************************************************************/

    }
    /**************************************************************************************************/

}

PasswordEditor::~PasswordEditor()
{
    delete ui;
}

void PasswordEditor::on_pB_saveNewPassword_clicked()
{
    /*******************************************
     * ricava la nuova password
     *******************************************/
    new_password = ui->lE_NewPassword->text();
    /*******************************************/


    /*******************************************************************************************************
     * aggiorna il file tmpSettings.txt
     *******************************************************************************************************/
    QFile outFile("/home/tinylap/BarcodeReaderFiles/Settings/tmpSettings.txt");
    outFile.remove();
    outFile.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream ts(&outFile);
    QString txt;
    txt = new_password;
    ts<<txt<<endl; //ts<<txt<<Qt::endl;

    ts<<flush; //ts<<Qt::flush;
    //ts<<txt<<Qt::endl<<Qt::flush;

    outFile.close();
    /*******************************************************************************************************/

    /*******************************************************************************************************
     * Encode tmpSettings.txt in Settings.qr
     *******************************************************************************************************/
    fstream fin, fout;
    int encKey = 0x4DE6E;
    string file = "/home/tinylap/BarcodeReaderFiles/Settings/tmpSettings.txt"; // file da criptare
    char c;

    fin.open(file,fstream::in);
    fout.open("/home/tinylap/BarcodeReaderFiles/Settings/Settings.qr",fstream::out); // file criptato

    while (fin >> noskipws >> c) {
        int temp = (c + encKey);

        // Write temp as char in
        // output file
        fout << (char)temp;
    }

    // Closing both files
    fin.close();
    fout.close();
    /*******************************************************************************************************/

    /******************************************************************************
     * Remove tmpSettings.txt
     ******************************************************************************/
    remove("/home/tinylap/BarcodeReaderFiles/Settings/tmpSettings.txt");
    /******************************************************************************/

    /***************************************************
     * disabilita il pulsante di salvataggio
     ***************************************************/
    ui->pB_saveNewPassword->setEnabled(false);
    /***************************************************/

    /**************************
     * Chiude l'interfaccia
     **************************/
    accept();
    /**************************/

}


void PasswordEditor::on_lE_CurrentPassword_editingFinished()
{
    if( (ui->lE_CurrentPassword->text()!=correct_passwordTmp) && (ui->lE_CurrentPassword->text()!=fisi_passwordTmp) ){
        QMessageBox::warning(this, "Warning", "Password attuale non corretta");
    }

    if( ( (ui->lE_CurrentPassword->text()==correct_passwordTmp) || (ui->lE_CurrentPassword->text()==fisi_passwordTmp) )
            && (ui->lE_NewPassword->text().isEmpty()==false) ){
        ui->pB_saveNewPassword->setEnabled(true);
    } else {
        //QMessageBox::warning(this, "Warning", "Password attuale non corretta");
        ui->pB_saveNewPassword->setEnabled(false);
    }

}


void PasswordEditor::on_lE_NewPassword_editingFinished()
{
    if( ( (ui->lE_CurrentPassword->text()==correct_passwordTmp) || (ui->lE_CurrentPassword->text()==fisi_passwordTmp) )
            && (ui->lE_NewPassword->text().isEmpty()==false) ){
        ui->pB_saveNewPassword->setEnabled(true);
    } else {
        ui->pB_saveNewPassword->setEnabled(false);
    }

}

//void enableSaveButton(){
//    if( ( (ui->lE_CurrentPassword->text()==correct_passwordTmp) || (ui->lE_CurrentPassword->text()==fisi_passwordTmp) )
//            && (ui->lE_NewPassword->text().isEmpty()==false) ){
//        ui->pB_saveNewPassword->setEnabled(true);
//    } else {
//        ui->pB_saveNewPassword->setEnabled(false);
//    }
//}

