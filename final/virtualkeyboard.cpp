#include "virtualkeyboard.h"
#include "ui_virtualkeyboard.h"
char value[256];
int char_count;

VirtualKeyboard::VirtualKeyboard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VirtualKeyboard)
{
    ui->setupUi(this);
}

VirtualKeyboard::~VirtualKeyboard()
{
    delete ui;
}

void VirtualKeyboard::on_One_clicked()
{
    value[char_count++] = '1';
    ui->TypedText->setText(value);
}

void VirtualKeyboard::on_Two_clicked()
{
    value[char_count++] = '2';
    ui->TypedText->setText(value);
}

void VirtualKeyboard::on_Three_clicked()
{
    value[char_count++] = '3';
    ui->TypedText->setText(value);
}

void VirtualKeyboard::on_Four_clicked()
{
    value[char_count++] = '4';
    ui->TypedText->setText(value);
}

void VirtualKeyboard::on_Five_clicked()
{
    value[char_count++] = '5';
    ui->TypedText->setText(value);
}

void VirtualKeyboard::on_Six_clicked()
{
    value[char_count++] = '6';
    ui->TypedText->setText(value);
}

void VirtualKeyboard::on_Seven_clicked()
{
    value[char_count++] = '7';
    ui->TypedText->setText(value);
}

void VirtualKeyboard::on_Eight_clicked()
{
    value[char_count++] = '8';
    ui->TypedText->setText(value);
}

void VirtualKeyboard::on_Nine_clicked()
{
    value[char_count++] = '9';
    ui->TypedText->setText(value);
}

void VirtualKeyboard::on_Dot_clicked()
{
    value[char_count++] = '.';
    ui->TypedText->setText(value);
}

void VirtualKeyboard::on_Zero_clicked()
{
    value[char_count++] = '0';
    ui->TypedText->setText(value);
}

void VirtualKeyboard::on_Backspace_clicked()
{
    value[--char_count] = NULL;
    ui->TypedText->setText(value);
}
