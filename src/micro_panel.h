#pragma once

class MicroPanel  {
protected:
	static class U8GLIB *u8g;
	static void refresh(MicroPanel *target);

public:
	MicroPanel();

	virtual void draw() = 0;
	virtual void refresh();

	static void reload();
	static void init(U8GLIB *_u8g);
};

class MicroPanelTerminal: public MicroPanel {
	virtual void draw();
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
	
	virtual void draw();
};

class MicroPanelCheck : public MicroPanelMenu {
public:
	uint8_t *checkedItem;
	
	MicroPanelCheck(const char **_menuItens, uint8_t *checkItem);
	
	virtual void draw();
};

class MicroPanelBigNumber: public MicroPanel {
public:
	uint16_t number;
	const char *title;
	
	MicroPanelBigNumber(const char *_title, uint16_t _number);
	
	virtual void draw();
};


