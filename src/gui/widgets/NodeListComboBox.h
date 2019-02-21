#pragma once

#include "session/Node.h"

namespace Element {

class NodeListComboBox : public ComboBox
{
public:
    NodeListComboBox()
    { 
        setTextWhenNoChoicesAvailable ("Empty graph");
        setTextWhenNothingSelected ("Select node");
    }

    virtual ~NodeListComboBox() { }

    void addNodes (const Node& parent)
    {
        int lastIndex = getSelectedItemIndex();

        clear();
        for (int i = 0; i < parent.getNumNodes(); ++i)
        {
            const auto node (parent.getNode (i));
            addItem (node.getName(), i + 1);
        }

        if (isPositiveAndBelow (jmin (lastIndex, getNumItems() - 1), getNumItems()))
            setSelectedItemIndex (lastIndex);
    }

    void selectNode (const Node& node)
    {
        const auto graph (node.getParentGraph());
        const int index = graph.getNodesValueTree().indexOf (node.getValueTree());
        if (isPositiveAndBelow (index, getNumItems()))
            setSelectedItemIndex (index);
    }
};

}