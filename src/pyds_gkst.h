/**
same struct on custom_schema.h on git@github.com:wk-gkst/ds-nvmsgconv
**/
#include <glib.h>

using namespace std;

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct NvDsPPEObject
{
    gchar *stream_id;
    gchar *frame_unique_id;
    gchar *frame;
    gchar *lcStatus;
    gchar *direction;
    guint hasVest;
    guint hasHelm;
    guint full;    
} NvDsPPEObject;

#ifdef __cplusplus
}
#endif
