/* See LICENSE file for copyright and license details. */

/* for media keys */
#include <X11/XF86keysym.h>

/* appearance */
static const unsigned int borderpx       = 1;        /* border pixel of windows */
static const unsigned int snap           = 32;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray             = 1;     /* 0 means no systray */
static const int showbar                 = 1;        /* 0 means no bar */
static const int topbar                  = 1;        /* 0 means bottom bar */
static const char *fonts[]               = { "monospace:size=10" };
static const char normbgcolor[]          = "#0e0f14";
static const char normbordercolor[]      = "#363b47";
static const char normfgcolor[]          = "#dfdfdf";
static const char selfgcolor[]           = "#eeeeee";
static const char selbordercolor[]       = "#555a63";
static const char selbgcolor[]           = "#282828";
static const unsigned int baralpha       = 0xff;
static const unsigned int borderalpha    = OPAQUE;

static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
	[SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor },
};

static const unsigned int alphas[][3]      = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};

/* tagging */
static const char *tags[] = { "", "", "", "", "", "", "", "", "", "" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class          instance  title tags mask iscentered  isfloating  monitor */
	{ "discord",      NULL,     NULL, 1 << 2,   0,          0,          1 },
	{ "Element",      NULL,     NULL, 1 << 2,   0,          0,          1 },
	{ "easyeffects",  NULL,     NULL, 1 << 9,   0,          0,          1 },
	{ "Pavucontrol",  NULL,     NULL, 1 << 9,   0,          0,          1 },
	{ "KeePassXC",    NULL,     NULL, 1 << 9,   0,          0,          0 },
	{ "firefox",      NULL,     NULL, 1 << 1,   0,          0,          -1 },
	{ "steam",        NULL,     NULL, 1 << 2,   0,          0,          0 },
	{ "Lutris",       NULL,     NULL, 1 << 2,   0,          0,          0 },
	{ "threema-web",  NULL,     NULL, 1 << 4,   0,          0,          1 },
	{ "thunderbird",  NULL,     NULL, 1 << 4,   0,          0,          1 },
	{ "Signal",       NULL,     NULL, 1 << 4,   0,          0,          1 },
	{ "Sonixd",       NULL,     NULL, 1 << 8,   0,          0,          1 },
};

/* layout(s) */
static const float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "M",      monocle },
	{ "T",      tile },    /* first entry is default */
	{ "D",      deck },
	{ "B",      bstack },
	{ "B",      bstackhoriz },
	{ "F",      NULL },    /* no layout function means floating behavior */
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,  view,       {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,  toggleview, {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,  tag,        {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,  toggletag,  {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

static Key keys[] = {
  /* modifier           key         function        argument */
  { MODKEY|ShiftMask,   XK_Escape,  quit,           {0} },
  { MODKEY|ShiftMask,   XK_b,       togglebar,      {0} },
  { MODKEY|ShiftMask,   XK_c,       setlayout,      {.v = &layouts[2]} },
  { MODKEY|ShiftMask,   XK_d,       togglefloating, {0} },
  { MODKEY|ShiftMask,   XK_f,       togglefullscr,  {0} },
  { MODKEY,             XK_h,       focusstack,     {.i = -1} },
  { MODKEY|ShiftMask,   XK_h,       zoom,           {0} },
  { MODKEY,             XK_j,       focusstack,     {.i = +1} },
  { MODKEY|ShiftMask,   XK_j,       zoom,           {0} },
  { MODKEY,             XK_k,       focusstack,     {.i = -1} },
  { MODKEY|ShiftMask,   XK_k,       zoom,           {0} },
  { MODKEY,             XK_l,       focusstack,     {.i = +1} },
  { MODKEY|ShiftMask,   XK_m,       setlayout,      {.v = &layouts[0]} },
  { MODKEY|ShiftMask,   XK_o,       setmfact,       {.f = +0.05} },
  { MODKEY|ShiftMask,   XK_q,       killclient,     {0} },
  { MODKEY|ShiftMask,   XK_t,       setlayout,      {.v = &layouts[1]} },
  { MODKEY|ShiftMask,   XK_u,       setlayout,      {.v = &layouts[3]} },
  { MODKEY|ShiftMask,   XK_v,       setlayout,      {.v = &layouts[4]} },
  { MODKEY|ShiftMask,   XK_z,       setmfact,       {.f = -0.05} },
  { MODKEY,             XK_0,       view,           {.ui = ~0} },
  { MODKEY|ShiftMask,   XK_0,       tag,            {.ui = ~0} },
  { MODKEY,             XK_comma,   focusmon,       {.i = -1} },
  { MODKEY,             XK_period,  focusmon,       {.i = +1} },
  { MODKEY|ShiftMask,   XK_comma,   tagmon,         {.i = -1} },
  { MODKEY|ShiftMask,   XK_period,  tagmon,         {.i = +1} },
  { Mod1Mask,           XK_Tab,     focusstack,     {.i = +1} },

  TAGKEYS(XK_1, 0)
  TAGKEYS(XK_2, 1)
  TAGKEYS(XK_3, 2)
  TAGKEYS(XK_4, 3)
  TAGKEYS(XK_5, 4)
  TAGKEYS(XK_6, 5)
  TAGKEYS(XK_7, 6)
  TAGKEYS(XK_8, 7)
  TAGKEYS(XK_9, 8)
  TAGKEYS(XK_0, 9)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
  /* click          event mask  button    function        argument */
  { ClkLtSymbol,    0,          Button1,  cyclelayout,    {.i = +1} },
  { ClkLtSymbol,    0,          Button2,  focusstack,     {.i = +1} },
  { ClkLtSymbol,    0,          Button3,  cyclelayout,    {.i = -1} },
  { ClkStatusText,  0,          Button1,  sigdwmblocks,   {.i = 1} },
  { ClkStatusText,  0,          Button2,  sigdwmblocks,   {.i = 2} },
  { ClkStatusText,  0,          Button3,  sigdwmblocks,   {.i = 3} },
  { ClkClientWin,   MODKEY,     Button1,  movemouse,      {0} },
  { ClkClientWin,   MODKEY,     Button2,  togglefloating, {0} },
  { ClkClientWin,   MODKEY,     Button3,  resizemouse,    {0} },
  { ClkTagBar,      0,          Button1,  view,           {0} },
  { ClkTagBar,      0,          Button3,  toggleview,     {0} },
  { ClkTagBar,      MODKEY,     Button1,  tag,            {0} },
  { ClkTagBar,      MODKEY,     Button3,  toggletag,      {0} },
};
