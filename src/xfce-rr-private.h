#ifndef XFCE_RR_PRIVATE_H
#define XFCE_RR_PRIVATE_H

#include <X11/Xlib.h>

#ifdef HAVE_RANDR
#include <X11/extensions/Xrandr.h>
#endif

typedef struct ScreenInfo ScreenInfo;

struct ScreenInfo
{
    int			min_width;
    int			max_width;
    int			min_height;
    int			max_height;

#ifdef HAVE_RANDR
    XRRScreenResources *resources;
#endif
    
    XfceRROutput **	outputs;
    XfceRRCrtc **	crtcs;
    XfceRRMode **	modes;
    
    XfceRRScreen *	screen;

    XfceRRMode **	clone_modes;

#ifdef HAVE_RANDR
    RROutput            primary;
#endif
};

struct XfceRRScreenPrivate
{
    GdkScreen *			gdk_screen;
    GdkWindow *			gdk_root;
    Display *			xdisplay;
    Screen *			xscreen;
    Window			xroot;
    ScreenInfo *		info;
    
    int				randr_event_base;
    int				rr_major_version;
    int				rr_minor_version;
    
    Atom                        connector_type_atom;
};

struct XfceRROutputInfoPrivate
{
    char *		name;

    gboolean		on;
    int			width;
    int			height;
    int			rate;
    int			x;
    int			y;
    XfceRRRotation	rotation;

    gboolean		connected;
    gchar		vendor[4];
    guint		product;
    guint		serial;
    double		aspect;
    int			pref_width;
    int			pref_height;
    char *		display_name;
    gboolean            primary;
};

gboolean _xfce_rr_output_name_is_laptop (const char *name);

#endif