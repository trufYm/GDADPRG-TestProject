#include "Renderer.hpp"

using namespace renderers;

Renderer::Renderer(std::string strName) : Component(strName, ComponentType::RENDERER){

}

void Renderer::assignTargetWindow(sf::RenderWindow* pWindow){

}

void Renderer::assignDrawable(sf::Drawable* pDrawable){

}