#include <compiled.h>
#include "Layer.h"

namespace Prophecy{
        Layer::Layer(const std::string &debugName): m_debugName(debugName)
        {
            std::cout << "Layer Constructed with name " << m_debugName << std::endl;
        }
};


