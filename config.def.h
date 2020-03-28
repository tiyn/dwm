/* See LICENSE file for copyright and license details. */

/* for media keys */
#include <X11/XF86keysym.h>

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=10", "Joypixels:pixelsize=10" };
static const char dmenufont[]       = "monospace:size=10";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class							instance							title       tags mask     isfloating   monitor */
	{ "Gimp",							NULL,								NULL,       0,            1,           -1 },
	{ "Firefox",						NULL,								NULL,       1 << 8,       0,           -1 },
	{ NULL,								"de.uol.swp.client.ClientApp",		NULL,       0,            1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-c", "-l", "20", NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *browsercmd[] = { "firefox", NULL };
static const char *filecmd[] = {"st", "-e", "vifm", NULL };
static const char *javaidecmd[] = {"intellij-idea-ultimate-edition", NULL };
static const char *mailcmd[] = {"thunderbird", NULL };
static const char *musiccmd[] = {"st", "-e", "ncmpcpp", NULL };
static const char *lockcmd[] = {"prompt", "Lock computer?", "slock", NULL };
static const char *rebootcmd[] = {"prompt", "Reboot computer?", "sudo -A shutdown -h now", NULL };
static const char *shutdowncmd[] = {"prompt", "Shutdown computer?", "sudo -A shutdown -h now", NULL };

static Key keys[] = {
	/* modifier                     key							function		argument */
	{ MODKEY|ShiftMask,             XK_Escape,					quit,			{0} },
	{ MODKEY,						XK_Return,					spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,						spawn,			{.v = browsercmd } },
	{ MODKEY|ShiftMask,             XK_b,						togglebar,      {0} },
	{ MODKEY,                       XK_d,						setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_f,						spawn,			{.v = filecmd } },
	{ MODKEY|ShiftMask,				XK_f,						setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_h,						focusstack,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_h,						zoom,			{0} },
	{ MODKEY,						XK_i,						spawn,			{.v = javaidecmd } },
	{ MODKEY,                       XK_j,						focusstack,     {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_j,						zoom,			{0} },
	{ MODKEY,                       XK_k,						focusstack,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_k,						zoom,			{0} },
	{ MODKEY,                       XK_l,						focusstack,     {.i = +1 } },
	{ MODKEY,						XK_m,						spawn,			{.v = mailcmd } },
	{ MODKEY|ShiftMask,             XK_o,						setmfact,       {.f = +0.05} },
	{ MODKEY,						XK_p,						spawn,			{.v = musiccmd } },
	{ MODKEY,						XK_q,						killclient,     {0} },
	{ MODKEY|ShiftMask,             XK_r,						spawn,          {.v = dmenucmd } },
	{ MODKEY,						XK_s,						spawn,          SHCMD("startpagesearch") },
	{ MODKEY,                       XK_t,						setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_z,						setmfact,       {.f = -0.05} },
	{ MODKEY,						XK_F5,						spawn,			SHCMD("togglemonitor") },
	{ MODKEY,						XK_F6,						spawn,			SHCMD("toggletouchpad") },
	{ MODKEY,						XK_F7,						spawn,			SHCMD("dmenumount") },
	{ MODKEY,						XK_F8,						spawn,			SHCMD("dmenuumount") },
	{ MODKEY,						XK_F9,						spawn,			SHCMD("sudo -A systemctl restart NetworkManager") },
	{ MODKEY,						XK_F10,						spawn,			{.v = lockcmd } },
	{ MODKEY,						XK_F11,						spawn,			{.v = rebootcmd } },
	{ MODKEY,						XK_F12,						spawn,			{.v = shutdowncmd } },
	{ 0,							XF86XK_AudioMute,			spawn,			SHCMD("lmc m; refbar") },
	{ 0,							XF86XK_AudioMicMute,		spawn,			SHCMD("pactl set-source-mute 1 toggle") },
	{ 0,							XF86XK_AudioLowerVolume,	spawn,			SHCMD("lmc down 5; refbar") },
	{ 0,							XF86XK_AudioRaiseVolume,	spawn,			SHCMD("lmc up 5; refbar") },
	{ 0,							XF86XK_MonBrightnessDown,	spawn,			SHCMD("light -U 15") },
	{ 0,							XF86XK_MonBrightnessUp,		spawn,			SHCMD("light -A 15") },
	//{ MODKEY|ShiftMask,             XK_o,      incnmaster,     {.i = +1 } },
	//{ MODKEY|ShiftMask,             XK_d,	   togglefloating, {0} },
	//{ MODKEY|ShiftMask,			  XK_z,      incnmaster,     {.i = -1 } },
	//{ MODKEY,                       XK_space,  setlayout,      {0} },
	//{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	//{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	//{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	//{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	//{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	//{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	//{ MODKEY,                       XK_F5,     xrdb,           {.v = NULL } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

