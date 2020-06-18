#pragma once

namespace Prophecy {
    class Layer {
    public:
        Layer(const std::string& debugName = "Layer");
//        virtual  ~Layer();

    protected:
        const std::string m_debugName;
    };
}
