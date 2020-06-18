#pragma once

#include <compiled.h>
#include <Prophecy/Core/Layer.h>


namespace Prophecy {
    class LayerStack {
    public:
        LayerStack() = default;
        ~LayerStack();

        static LayerStack* m_Instance;
        static LayerStack* Get();

        void addLayer(Layer* layer);

    protected:
        std::vector<Layer*> m_Stack;
    };
}