/*
 * Copyright 2014 The Imaging Source Europe GmbH
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _GST_TCAMAUTOFOCUS_H_
#define _GST_TCAMAUTOFOCUS_H_

#include <gst/base/gstbasetransform.h>
#include "AutoFocus.h"

G_BEGIN_DECLS

#define GST_TYPE_TCAMAUTOFOCUS            (gst_tcamautofocus_get_type())
#define GST_TCAMAUTOFOCUS(obj)            (G_TYPE_CHECK_INSTANCE_CAST((obj), GST_TYPE_TCAMAUTOFOCUS, GstTcamAutoFocus))
#define GST_TCAMAUTOFOCUS_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST((klass), GST_TYPE_TCAMAUTOFOCUS, GstTcamAutoFocusClass))
#define GST_IS_TCAMAUTOFOCUS(obj)         (G_TYPE_CHECK_INSTANCE_TYPE((obj), GST_TYPE_TCAMAUTOFOCUS))
#define GST_IS_TCAMAUTOFOCUS_CLASS(obj)   (G_TYPE_CHECK_CLASS_TYPE((klass), GST_TYPE_TCAMAUTOFOCUS))


typedef unsigned char byte;

enum CAMERA_TYPE
{
    CAMERA_TYPE_UNKNOWN = 0,
    CAMERA_TYPE_ARAVIS,
    CAMERA_TYPE_USB,
    CAMERA_TYPE_TCAM,
};


/* names of gstreamer elements used for camera interaction */
/* static const char* CAMERASRC_NETWORK = "GstAravis"; */

typedef struct GstTcamAutoFocus
{
    GstBaseTransform base_tis_auto_exposure;

    GstPad *sinkpad;
    GstPad *srcpad;

    enum CAMERA_TYPE camera_type;

    unsigned int width;
    unsigned int height;

    unsigned int framerate_numerator;
    unsigned int framerate_denominator;

    gboolean focus_active;

    GstElement* camera_src;
    AutoFocus* focus;

    guint cur_focus;
    guint x;
    guint y;
    guint size;


} GstTcamAutoFocus;

typedef struct GstTcamAutoFocusClass
{
    GstBaseTransformClass base_tcamautofocus_class;
} GstTcamAutoFocusClass;

GType gst_tcamautofocus_get_type (void);

G_END_DECLS

#endif /* _GST_TCAMAUTOFOCUS_H_ */