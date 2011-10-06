 /*
 * Created by: Dr. Strangecode
 * ---------------------------------------------
 * This is free code, it can be used, modified,
 * destroyed, raped and whatever without limits.
 * I own no copyrights over it.
 * This code is provided AS IS without warranty
 * of any kind either expressed or implied,
 * including but not limited to the implied
 * warranties of merchantability and/or fitness
 * for a particular purpose.
 * ---------------------------------------------
 * For more free code visit http://drstrangecode.org
 */

#include "Form1.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::Graphics;
using namespace Osp::App;

Form1::Form1(void) {
}

Form1::~Form1(void) {
}

bool Form1::Initialize() {
    // Construct an XML form
    Construct(L"IDF_FORM1");

    return true;
}

result Form1::OnInitializing(void) {
    result r = E_SUCCESS;

    pListView = static_cast<GroupedListView *> (GetControl(L"IDC_GROUPEDLISTVIEW"));
    pListView->SetItemProvider(*this);
    pListView->AddGroupedListViewItemEventListener(*this);
    pListView->SetSweepEnabled(true);

    return r;
}

result Form1::OnTerminating(void) {
    result r = E_SUCCESS;

    return r;
}

// IGroupedListViewItemEventListener
void Form1::OnGroupedListViewContextItemStateChanged(Osp::Ui::Controls::GroupedListView &listView,
                                                     int groupIndex,
                                                     int itemIndex,
                                                     int elementId,
                                                     Osp::Ui::Controls::ListContextItemStatus state) {

	AppLog("OnGroupedListViewContextItemStateChanged() : Group: %d Item: %d", groupIndex, itemIndex);
}

void Form1::OnGroupedListViewItemStateChanged(Osp::Ui::Controls::GroupedListView &listView,
                                              int groupIndex,
                                              int itemIndex,
                                              int elementId,
                                              Osp::Ui::Controls::ListItemStatus state) {

	AppLog("OnGroupedListViewItemStateChanged() : Group: %d Item: %d", groupIndex, itemIndex);
	switch (state) {
		case LIST_ITEM_STATUS_CHECKED:
			AppLog("LIST_ITEM_STATUS_CHECKED");
		break;
		case LIST_ITEM_STATUS_HIGHLIGHTED:
			AppLog("LIST_ITEM_STATUS_HIGHLIGHTED");
		break;
		case LIST_ITEM_STATUS_MORE:
			AppLog("LIST_ITEM_STATUS_MORE");
		break;
		case LIST_ITEM_STATUS_SELECTED:
			AppLog("LIST_ITEM_STATUS_SELECTED");
		break;
		case LIST_ITEM_STATUS_UNCHECKED:
			AppLog("LIST_ITEM_STATUS_UNCHECKED");
		break;
	}
}

void Form1::OnGroupedListViewItemSwept(Osp::Ui::Controls::GroupedListView &listView,
                                       int groupIndex,
                                       int itemIndex,
                                       Osp::Ui::Controls::SweepDirection direction) {

	AppLog("OnGroupedListViewItemSwept() : Group: %d Item: %d", groupIndex, itemIndex);
	switch (direction) {
	case SWEEP_DIRECTION_LEFT:
		AppLog("SWEEP_DIRECTION_LEFT");
	break;
	case SWEEP_DIRECTION_RIGHT:
		AppLog("SWEEP_DIRECTION_RIGHT");
	break;
	}
}

void Form1::OnGroupedListViewItemLongPressed(Osp::Ui::Controls::GroupedListView & listView,
                                             int  groupIndex,
                                             int  itemIndex,
                                             int  elementId,
                                             bool & invokeListViewItemCallback) {

	AppLog("OnGroupedListViewItemLongPressed() : Group: %d Item: %d", groupIndex, itemIndex);
}

// IGroupedListViewItemProvider
int Form1::GetGroupCount(void) {
	/* 5 groups */
    return 5;
}

int Form1::GetItemCount(int groupIndex) {
	/* Group 0 has 1 item
	 * Group 1 has 2 items
	 * Group 2 has 3 items
	 * Group 3 has 4 items
	 * Group 4 has 5 items
	 * */
    return groupIndex + 1;
}

Osp::Ui::Controls::GroupItem* Form1::CreateGroupItem(int groupIndex, int itemWidth) {
    GroupItem* pItem = new GroupItem();
    pItem->Construct(Dimension(itemWidth, 32));
    String text;
    text.Format(100, L"Group #%d", groupIndex);

    /* You can also set a bitmap in group items,
     * just pass a Bitmap pointer as the second
     * parameter to the GroupItem::SetElement() */
    pItem->SetElement(text, null);

    /* You can set a custom background color to group items */
    // pItem->SetBackgroundColor(Color::COLOR_BLACK);

    /* You can set a custom text size */
    // pItem->SetTextSize(26);

    return pItem;

}

Osp::Ui::Controls::ListItemBase* Form1::CreateItem(int groupIndex, int itemIndex, int itemWidth) {

    String text;
    text.Format(100, L"SimpleItem #%d", itemIndex);

	AppResource * res = Application::GetInstance()->GetAppResource();
	Bitmap * pBitmap = res->GetBitmapN(L"itemicon.png",
			                           BITMAP_PIXEL_FORMAT_ARGB8888);

	SimpleItem * pItem = new SimpleItem();

	pItem->Construct(Dimension(itemWidth, 100), LIST_ANNEX_STYLE_DETAILED);
	pItem->SetElement(text, pBitmap);

	delete pBitmap;

    return pItem;

}

bool Form1::DeleteGroupItem(int groupIndex, Osp::Ui::Controls::GroupItem* pItem, int itemWidth) {
	/* pItem is not deleted here */
	return false;
}

bool Form1::DeleteItem(int groupIndex,
                       int itemIndex,
                       Osp::Ui::Controls::ListItemBase* pItem,
                       int itemWidth) {
	/* pItem is not deleted here */
	return false;
}
