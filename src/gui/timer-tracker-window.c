/* timer-tracker-window.c
 *
 * Copyright 2024 Eric Jawaid Marty
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "config.h"

#include "timer-tracker-window.h"

struct _TimerTrackerWindow
{
  AdwApplicationWindow  parent_instance;

  AdwHeaderBar *header_bar;
  GtkLabel *timer;
  GtkButton *start_pause_button;
  GtkButton *save_button;
  GtkLabel *inc;
};

G_DEFINE_FINAL_TYPE (TimerTrackerWindow, timer_tracker_window, ADW_TYPE_APPLICATION_WINDOW)

static void
start_pause_handler (TimerTrackerWindow *win)
{
  g_message("start_pause");
}

static void
save_handler (TimerTrackerWindow *win)
{
  g_message("save");
}

static void
timer_tracker_window_class_init (TimerTrackerWindowClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/net/ejmtech/TimerTracker/gui/timer-tracker-window.ui");
  gtk_widget_class_bind_template_child (widget_class, TimerTrackerWindow, header_bar);
  gtk_widget_class_bind_template_child (widget_class, TimerTrackerWindow, timer);
  gtk_widget_class_bind_template_child (widget_class, TimerTrackerWindow, start_pause_button);
  gtk_widget_class_bind_template_child (widget_class, TimerTrackerWindow, save_button);
  gtk_widget_class_bind_template_child (widget_class, TimerTrackerWindow, inc);

  gtk_widget_class_bind_template_callback(widget_class, save_handler);
  gtk_widget_class_bind_template_callback(widget_class, start_pause_handler);
}

static void
timer_tracker_window_init (TimerTrackerWindow *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
