#pragma once
#include "Button.h"
#include "Head.h"
#include "Menu.h"

//����ѡ������еĽ�ɫ�����Դ���һ��item��Ϊ���ˣ�Ϊ�ջ���ʾ������
class TeamMenu : public Menu
{
public:
    TeamMenu();
    ~TeamMenu();

private:
    std::vector<std::shared_ptr<Head>> heads_;
    //std::set<int> selected_;
    Role* role_ = nullptr;
    Item* item_ = nullptr;
    int mode_ = 0;    //Ϊ0�ǵ�ѡ��Ϊ1�Ƕ�ѡ

    std::shared_ptr<Button> button_all_, button_ok_;

public:
    void setItem(Item* item) { item_ = item; }
    void setMode(int m) { mode_ = m; }

    virtual void onEntrance() override;
    virtual void draw() override;
    virtual void onPressedOK() override;
    virtual void onPressedCancel() override;
    virtual void dealEvent(BP_Event& e) override;

    Role* getRole();
    std::vector<Role*> getRoles();
};
