

#include "GUI.h"
#include "qformlayout.h"
#include "qgridlayout.h"
//#include "CSVShoppingBasket.h"
//#include "HTMLShoppingBasket.h"
#include "qlabel.h"
#include <iostream>
#include <QMessageBox>
#include "HTMLRepo.h"
#include<QPainter>
#include<QLabel>
#include<QVector>
#include<unordered_map>
#include<algorithm>

#include"UserGui.h"
#include"AdminGui.h"


using namespace std;
GUI::GUI(Service &service, QWidget* parent): service{service}, QMainWindow(parent)
{
    this->initGUI();
    this->connectSignalsAndSlots();
}

void GUI::initGUI() {

    QFont buttonsFont("Consolas", 13, true);

    this->saveButton = new QPushButton{"Save File Type"};
    this->saveButton->setFont(buttonsFont);

    this->adminModeButton = new QPushButton{"Admin Mode"};
    this->adminModeButton->setFont(buttonsFont);

    this->userModeButton = new QPushButton{"User Mode"};
    this->userModeButton->setFont(buttonsFont);

    this->openChart = new QPushButton{"Open Chart"};
    this->openChart->setFont(buttonsFont);

    this->filetypeComboBox = new QComboBox{};
    this->filetypeComboBox->setFont(buttonsFont);
    this->filetypeComboBox->addItem("CSV File");
    this->filetypeComboBox->addItem("HTML File");

    QVBoxLayout* mainLayout = new QVBoxLayout();

    QLabel *introduction = new QLabel();
    introduction->setText("☺ WELCOME TO THE TRENCH COATS SHOP ☺");
    introduction->setAlignment(Qt::AlignCenter);
    QFont introduction_font("Consolas", 20, true, true);
    introduction->setFont(introduction_font);

    QLabel *space = new QLabel();
    space->setText("");

    QLabel *filename = new QLabel();
    filename->setText("Choose the type of the file");
    QFont font_filename("Consolas", 15, true);
    filename->setFont(font_filename);

    mainLayout->addWidget(introduction);
    mainLayout->addWidget(space);
    mainLayout->addWidget(space);

    QFormLayout* fileDetails = new QFormLayout();
    fileDetails->addRow(filename, this->filetypeComboBox);

    mainLayout->addLayout(fileDetails);

    QGridLayout* buttonsLayout = new QGridLayout();
    buttonsLayout->addWidget(this->saveButton, 0, 0);
    buttonsLayout->addWidget(this->userModeButton, 1, 0);
    buttonsLayout->addWidget(this->adminModeButton, 2, 0);
    buttonsLayout->addWidget(this->openChart, 3, 0);

    mainLayout->addLayout(buttonsLayout);

    QWidget *mainWindow = new QWidget();
    mainWindow->setLayout(mainLayout);
    setCentralWidget(mainWindow);


}

void GUI::connectSignalsAndSlots() {
    QObject::connect(this->saveButton, &QPushButton::clicked, this, &GUI::saveFileType);
    QObject::connect(this->userModeButton, &QPushButton::clicked, this, &GUI::startUserModeGUI);
    QObject::connect(this->adminModeButton, &QPushButton::clicked, this, &GUI::startAdminModeGUI);;
    QObject::connect(this->openChart, &QPushButton::clicked, this, &GUI::createChart);
}

void GUI::startUserModeGUI() {
    if(type == "empty") {
        QMessageBox::critical(this, "Error", "You have to choose a type for the file first!");
        return;
    }
    else {
        this->setCursor(Qt::WaitCursor);
        UserModeGUI* umg = new UserModeGUI{service};
//        umg->show();
        this->setCursor(Qt::ArrowCursor);
    }
}

void GUI::startAdminModeGUI() {
    if (type == "empty") {
        QMessageBox::critical(this, "Error", "You have to choose a type for the file first!");
        return;
    } else {
        this->setCursor(Qt::WaitCursor);
       // AdminModeGUI* amg = new AdminModeGUI{service};
        AdminGui*amg =new AdminGui{service};
//        amg->show();
        this->setCursor(Qt::ArrowCursor);
    }
}

void GUI::saveFileType() {
    this->type= this->filetypeComboBox->currentText().toStdString();
    if(this->type == "CSV File"){
        //this->ASB = new CSVShoppingBasket();
        this->service.setTypeOfRepo(new FileRepo{"coats.txt"});
        this->service.setBasket(new FileRepo{"Basket.txt"});}
    else if(this->type == "HTML File") {
        this->service.setTypeOfRepo(new FileRepo{"coats.txt"});
        this->service.setBasket(new HTMLRepo{"Basket.html"});
}
}

GUI::~GUI() {

}

void GUI::createChart() {
    // Retrieve coat data from the service
    std::vector<Coat> coats = service.getCoats();

    // Count the occurrences of each coat color
    std::unordered_map<QString, int> colorCounts;
    for (const auto& coat : coats) {
        QString color = QString::fromStdString(coat.getColour());
        colorCounts[color]++;
    }

    // Convert color counts to QVector for easier processing
    QVector<int> data;
    QVector<QColor> colors;
    for (const auto& pair : colorCounts) {
        data.push_back(pair.second);
        colors.push_back(QColor(pair.first));
    }

    // Create a QImage to draw on
    QImage image(600, 400, QImage::Format_RGB32);
    QPainter painter(&image);

    // Clear the image with a white background
    painter.fillRect(image.rect(), Qt::white);

    // Calculate the maximum value in the data
    int maxValue = *std::max_element(data.begin(), data.end());

    // Define dimensions for the chart
    int chartWidth = 500;
    int chartHeight = 300;
    int barWidth = chartWidth / data.size();
    int barSpacing = 10;

    // Draw the bars
    for (int i = 0; i < data.size(); ++i) {
        int barHeight = static_cast<int>(static_cast<double>(data[i]) / maxValue * chartHeight);
        QRect barRect(i * (barWidth + barSpacing), chartHeight - barHeight, barWidth, barHeight);
        painter.fillRect(barRect, colors[i]);
    }

    // Draw the axes
    painter.setPen(Qt::black);
    painter.drawLine(0, 0, 0, chartHeight); // Y-axis
    painter.drawLine(0, chartHeight, chartWidth, chartHeight); // X-axis


    // Draw labels on the X-axis
    for (int i = 0; i < data.size(); ++i) {
        painter.drawText(i * (barWidth + barSpacing) + barWidth / 2, chartHeight + 20, QString::number(data[i]));
    }


    // Display the chart
    QImage scaledImage = image.scaled(600, 400, Qt::KeepAspectRatio);
    QLabel *chartLabel = new QLabel();
    chartLabel->setPixmap(QPixmap::fromImage(scaledImage));
    chartLabel->show();
}











