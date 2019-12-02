#include "Button.h"
#include "DrawableOnCall.h"
#include "InputBox.h"
#include "Menu.h"

#include <functional>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

class SuperMenuText : public InputBox
{
public:
    SuperMenuText(const std::string& title, int font_size, const std::vector<std::pair<int, std::string>>& allItems, int itemsPerPage);
    virtual ~SuperMenuText() = default;
    void dealEvent(BP_Event& e) override;
    virtual void setInputPosition(int x, int y) override;
    void addDrawableOnCall(std::shared_ptr<DrawableOnCall> doc);
    void setMatchFunction(std::function<bool(const std::string&, const std::string&)> match);

private:
    void defaultPage();
    void flipPage(int pInc);
    void search(const std::string& text);
    void updateMaxPages();
    bool defaultMatch(const std::string& input, const std::string& name);

    std::shared_ptr<Button> previous_, next_;
    int curPage_ = 0;
    int maxPages_ = 1;
    int itemsPerPage_ = 10;
    bool curDefault_ = false;
    std::shared_ptr<MenuText> selections_;

    // ���е�
    std::vector<std::pair<int, std::string>> items_;

    // ���ǵ�ǰ����ʾ�ģ�����result -> items_[activeIndices[result]] ����ʵ��ѡ��
    // ֻ��ʾһҳ��activeIndices
    std::vector<int> activeIndices_;
    // �����������
    std::vector<int> searchResultIndices_;
    std::vector<std::shared_ptr<DrawableOnCall>> docs_;
    std::function<bool(const std::string&, const std::string&)> matchFunc_;

    // Ԥ����
    std::unordered_map<std::string, std::unordered_set<std::string>> matches_;
};