#ifndef __ROCCAT_KIRO_BUTTONS_FRAME_H__
#define __ROCCAT_KIRO_BUTTONS_FRAME_H__

/*
 * This file is part of roccat-tools.
 *
 * roccat-tools is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * roccat-tools is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with roccat-tools. If not, see <http://www.gnu.org/licenses/>.
 */

#include "kiro_profile_data.h"
#include <gtk/gtk.h>

G_BEGIN_DECLS

#define KIRO_BUTTONS_FRAME_TYPE (kiro_buttons_frame_get_type())
#define KIRO_BUTTONS_FRAME(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), KIRO_BUTTONS_FRAME_TYPE, KiroButtonsFrame))
#define IS_KIRO_BUTTONS_FRAME(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), KIRO_BUTTONS_FRAME_TYPE))

typedef struct _KiroButtonsFrame KiroButtonsFrame;

GType kiro_buttons_frame_get_type(void);
GtkWidget *kiro_buttons_frame_new(void);

void kiro_buttons_frame_set_from_profile_data(KiroButtonsFrame *buttons_frame, KiroProfileData const *profile_data);
void kiro_buttons_frame_update_profile_data(KiroButtonsFrame *buttons_frame, KiroProfileData *profile_data);

void kiro_buttons_frame_change_handedness(KiroButtonsFrame *buttons_frame);

G_END_DECLS

#endif
