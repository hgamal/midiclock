#pragma once

class MicroPanel  {
protected:
	static class U8GLIB *u8g;
	static void drawScreen(MicroPanel *target);
	virtual void _draw() = 0;

public:
	MicroPanel();

	virtual void draw();

	static void reload();
	static void init(U8GLIB *_u8g);
};

class MicroPanelTerminal: public MicroPanel {
	virtual void _draw();
public:
	MicroPanelTerminal();

	virtual void clear();
	virtual int  printf(const char *format, ...);
	virtual void puts(const char *p);
};

class MicroPanelMenu : public MicroPanel {
protected:
	uint8_t menuItensCount = 4;
	uint8_t menuCurrent = 0;
	const char **menuStrings;

public:
	MicroPanelMenu(const char **_menuItens);
	void updateMenu(int8_t dir);
	uint8_t getCurrItem(void);
	void setCurrItem(uint8_t pos);
	
	virtual void _draw();
};

class MicroPanelCheck : public MicroPanelMenu {
public:
	uint8_t *checkedItem;
	
	MicroPanelCheck(const char **_menuItens, uint8_t *checkItem);
	
	virtual void _draw();
};

class MicroPanelBigNumber: public MicroPanel {
public:
	uint16_t number;
	const char *title;
	
	MicroPanelBigNumber(const char *_title, uint16_t _number);
	
	virtual void _draw();
};


