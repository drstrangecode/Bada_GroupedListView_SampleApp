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

#ifndef _FORM1_H_
#define _FORM1_H_

#include <FBase.h>
#include <FUi.h>
#include <FGraphics.h>
#include <FApp.h>

class Form1 : public Osp::Ui::Controls::Form,
        public Osp::Ui::Controls::IGroupedListViewItemEventListener,
        public Osp::Ui::Controls::IGroupedListViewItemProvider {

        // Construction
    public:
        Form1(void);
        virtual ~Form1(void);
        bool Initialize(void);

        static const int ID_FORMAT_STRING = 100;
        static const int ID_FORMAT_BITMAP = 101;
        static const int ID_CONTEXT_ITEM_1 = 102;
        static const int ID_CONTEXT_ITEM_2 = 103;

        // Implementation
    protected:
        Osp::Ui::Controls::GroupedListView *pListView;

    public:
        virtual result OnInitializing(void);
        virtual result OnTerminating(void);

        // IGroupedListViewItemEventListener
        virtual void
        OnGroupedListViewContextItemStateChanged(Osp::Ui::Controls::GroupedListView &listView,
                                                 int groupIndex,
                                                 int itemIndex,
                                                 int elementId,
                                                 Osp::Ui::Controls::ListContextItemStatus state);
        virtual void
        OnGroupedListViewItemStateChanged(Osp::Ui::Controls::GroupedListView &listView,
                                          int groupIndex,
                                          int itemIndex,
                                          int elementId,
                                          Osp::Ui::Controls::ListItemStatus state);
        virtual void OnGroupedListViewItemSwept(Osp::Ui::Controls::GroupedListView &listView,
                                                int groupIndex,
                                                int itemIndex,
                                                Osp::Ui::Controls::SweepDirection direction);

        virtual void OnGroupedListViewItemLongPressed(Osp::Ui::Controls::GroupedListView & listView,
                                                      int  groupIndex,
                                                      int  itemIndex,
                                                      int  elementId,
                                                      bool & invokeListViewItemCallback);


        // IGroupedListViewItemProvider
        virtual int GetGroupCount(void);
        virtual int GetItemCount(int groupIndex);
        virtual Osp::Ui::Controls::GroupItem* CreateGroupItem(int groupIndex, int itemWidth);
        virtual bool DeleteGroupItem(int groupIndex,
                                     Osp::Ui::Controls::GroupItem* pItem,
                                     int itemWidth);
        virtual Osp::Ui::Controls::ListItemBase* CreateItem(int groupIndex,
                                                            int itemIndex,
                                                            int itemWidth);
        virtual bool DeleteItem(int groupIndex,
                                int itemIndex,
                                Osp::Ui::Controls::ListItemBase* pItem,
                                int itemWidth);

};

#endif	//_FORM1_H_
