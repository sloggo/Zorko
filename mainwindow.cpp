#include "mainwindow.h"
#include "InputHandler.h"
#include "ui_mainwindow.h"
#include "utils.h"
#include "GameState.h"
#include <iostream>
#include "QtWidgets"
#include "BattleHandler.h"
#include "Player.h"
#include "Potion.h"
using namespace std;

extern vector<Room*> rooms;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , Observer(1)
    , state(GameState(false))
    , battleHandler(nullptr)
{
    ui->setupUi(this);
    // Assuming 'button' is your QPushButton
    connect(ui->pushButton, &QPushButton::released, this, &MainWindow::continueButton);
    connect(ui->northBut, &QPushButton::released, this, &MainWindow::northButton);
    connect(ui->southBut, &QPushButton::released, this, &MainWindow::southButton);
    connect(ui->eastBut, &QPushButton::released, this, &MainWindow::eastButton);
    connect(ui->westBut, &QPushButton::released, this, &MainWindow::westButton);
    connect(ui->attackBut, &QPushButton::released, this, &MainWindow::attackButton);
    connect(ui->blockBut, &QPushButton::released, this, &MainWindow::blockButton);

    state.addObserver(this);
    state.addToPlayer();
    state.update(make_pair(0,0));
    state.update(0);
    ui->progressBar->setRange(0, state.getCurrentRoom()->getAllStages().size()-2); // Let's say it goes from 0 to 100
    ui->progressBar->setValue(state.getCurrentRoom()->counter); // With a current value of 10
    updatePlayerHealth();
    state.runGame();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeText(string input){
    QListWidgetItem* item = new QListWidgetItem;
    item->setText(QString::fromStdString(input));

    if(ui->listWidget->count() == 0){
        ui->listWidget->addItem(item);
    }else if(ui->listWidget->item(ui->listWidget->currentRow()) && item->text() != ui->listWidget->item(ui->listWidget->currentRow())->text()){
        ui->listWidget->addItem(item);
    }

    ui->listWidget->scrollToBottom();
}

void MainWindow::continueButton(){
    state.runNextRoom();
}

void MainWindow::northButton(){
    InputHandler* handler = InputHandler::getInstance();
    cout << "button pressed" << endl;
    handler->processUI("north");
    state.getCurrentRoom()->nextStage();
}

void MainWindow::southButton(){
    InputHandler* handler = InputHandler::getInstance();
    handler->processUI("south");
    state.getCurrentRoom()->nextStage();
}

void MainWindow::eastButton(){
    InputHandler* handler = InputHandler::getInstance();
    handler->processUI("east");
    state.getCurrentRoom()->nextStage();
}

void MainWindow::westButton(){
    InputHandler* handler = InputHandler::getInstance();
    handler->processUI("west");
    state.getCurrentRoom()->nextStage();
}

void MainWindow::updateR(Room* r){
    cout << "update called" << endl;
    r->runUI();
    changeText(r->getCurrentStage()->getText());

    if(r->getCurrentStage()->getType() == "battle"){
        setVisibilityBattleUI(true);
        setVisibilityRegUI(false);
        battleHandler = new BattleHandler(state.getCurrentRoom()->getCurrentStage()->id,getEnemyFromId(state.getCurrentRoom()->getCurrentStage()->id));
        vector<string> texts = battleHandler->initBattleUI();
        for(string t: texts){
            changeText(t);
        }
        ui->listWidget->scrollToBottom();
    } else{
        setVisibilityBattleUI(false);
        setVisibilityRegUI(true);
    }

    if(r->getCurrentStage()->getType() != "move"){
        ui->northBut->setEnabled(false);
        ui->southBut->setEnabled(false);
        ui->eastBut->setEnabled(false);
        ui->westBut->setEnabled(false);

        ui->pushButton->setEnabled(true);
    } else{
        ui->northBut->setEnabled(true);
        ui->southBut->setEnabled(true);
        ui->eastBut->setEnabled(true);
        ui->westBut->setEnabled(true);
        validRoomsToMove();

        ui->pushButton->setEnabled(false);
    }

    renderInventory();

    ui->progressBar->setRange(0, r->getAllStages().size()-2); // Let's say it goes from 0 to 100
    ui->progressBar->setValue(r->counter); // With a current value of 10
    updatePlayerHealth();
}

void MainWindow::setVisibilityRegUI(bool opt){
    ui->northBut->setVisible(opt);
    ui->southBut->setVisible(opt);
    ui->eastBut->setVisible(opt);
    ui->westBut->setVisible(opt);
    ui->pushButton->setVisible(opt);
}

void MainWindow::renderInventory(){
    ui->tableWidget->clear();
    Player* plyr = Player::getInstance();
    vector<Item*> inv = plyr->getInventory();

    ui->tableWidget->setRowCount(inv.size());
    ui->tableWidget->setColumnCount(4);
    const QStringList name = {"Item Name", "Item Description","Damage/HP", "Equip/Use"};
    ui->tableWidget->setHorizontalHeaderLabels(name);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);


    for(int i=0; i < inv.size(); i++){
        ui->tableWidget->setItem(i,0, new QTableWidgetItem(QString::fromStdString(inv[i]->getName())));
        ui->tableWidget->setItem(i,1, new QTableWidgetItem(QString::fromStdString(inv[i]->getDescription())));
        QPushButton* but = new QPushButton();
        but->setParent(ui->tableWidget);
        if(inv[i]->getId() == plyr->getWeapon()->getId()){
            but->setEnabled(false);
        }
        connect(but, &QPushButton::released, this, [=]() {
            equipButton(inv[i]);
        });
        ui->tableWidget->setItem(i,2, new QTableWidgetItem(QString::number(inv[i]->returnUIValue())));
        ui->tableWidget->setCellWidget(i,3, but);
    }

    ui->tableWidget->scrollToBottom();
}


void MainWindow::setVisibilityBattleUI(bool opt){
    ui->attackBut->setVisible(opt);
    ui->blockBut->setVisible(opt);
}

void MainWindow::attackButton(){
    vector<string> texts = battleHandler->playerMoveUI("attack");
    for(string t: texts){
        changeText(t);
    }
    ui->listWidget->scrollToBottom();
    if(texts[texts.size()-1] == "You win!"){
        continueButton();
    }
    updatePlayerHealth();
}

void MainWindow::blockButton(){
    vector<string> texts = battleHandler->playerMoveUI("block");
    for(string t: texts){
        changeText(t);
    }
    updatePlayerHealth();
}

void MainWindow::updatePlayerHealth(){
    Player* plyr = Player::getInstance();
    cout << plyr->getHp() << endl;
    ui->HealthBar->setRange(0, 100);
    ui->HealthBar->setValue(plyr->getHp());
}

void MainWindow::validRoomsToMove(){
    pair<int,int> currentLoc = make_pair(state.getCurrentRoom()->getLoc().first, state.getCurrentRoom()->getLoc().second);

    if(getRoomFromLocation(make_pair(currentLoc.first, currentLoc.second+1)) == nullptr){
        ui->northBut->setEnabled(false);
    }
    if(getRoomFromLocation(make_pair(currentLoc.first, currentLoc.second-1)) == nullptr){
        ui->southBut->setEnabled(false);
    }
    if(getRoomFromLocation(make_pair(currentLoc.first+1, currentLoc.second)) == nullptr){
        ui->eastBut->setEnabled(false);
    }
    if(getRoomFromLocation(make_pair(currentLoc.first-1, currentLoc.second)) == nullptr){
        ui->westBut->setEnabled(false);
    }
}

void MainWindow::equipButton(Item* item){
    Player* plyr = Player::getInstance();
    cout << "equip button"<<endl;
    std::cout << "Type of inv[i]: " << typeid(item).name() << std::endl;

    if(Weapon* weapon = dynamic_cast<Weapon*>(item)){
        cout << "Weapon" << endl;
        plyr->equipWeapon(weapon);
        cout << plyr->getWeapon()->getName() << endl;
        renderInventory();
    } else{
        cout << "Other" << endl;
        item->use();
        changeText("You used - "+item->getName()+"!");
        renderInventory();
    }

    updatePlayerHealth();
}
