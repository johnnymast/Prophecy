#include "LayerStack.h"
#include <Prophecy.h>

namespace Prophecy {

    LayerStack* LayerStack::m_Instance = 0;

    LayerStack::~LayerStack()
    {
        for (Layer* layer : m_Stack) {
            delete layer;
        }
    }

    void LayerStack::addLayer(Layer* layer) {
        m_Stack.push_back(layer);
    }

    LayerStack *LayerStack::Get() {
        if (m_Instance == 0)
        {
            m_Instance = new LayerStack();
        }

        return m_Instance;
    }
}