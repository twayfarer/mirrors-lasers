#ifndef GAME_INST_HPP
#define GAME_INST_HPP

#include "Scene.hpp"
#include "SelectListener.hpp"
#include "ResourceManager.hpp"
#include <vector>

/*#include <SFGUI/Button.hpp>
#include <SFGUI/Window.hpp>
#include <SFGUI/Notebook.hpp>
#include <SFGUI/Table.hpp>
#include <SFGUI/Label.hpp>*/

class Block;
class Renderer;

namespace sf {
	class Sprite;
}

class GameInst : public Scene
{
public:
	GameInst(GUIManager& a_GUIMgr, ResourceManager& a_ResMgr, Renderer& a_Renderer);
	bool Start();
	void Stop();
	void LoadLevel();
	void UnloadLevel();
	virtual void Update(float a_dt);
	virtual void UpdateGUISizes();
	//
	//sfg::Button::Ptr m_pQuitMenuButton;
	//sfg::Notebook::Ptr m_pListView;
	//sfg::Window::Ptr m_pDetailView;
	//
	void Select(void* a_pSelectee, SelectListener::Type a_SelectedType);
	//
private:
	std::vector<Block*> m_blocks;
	std::vector<SpriteID> m_laserSprites;
	bool m_Running;
	SelectListener* m_pSelectListener;
	Renderer& m_Renderer;

	int startX;
	int startY;
};

#endif	//GAME_INST_HPP