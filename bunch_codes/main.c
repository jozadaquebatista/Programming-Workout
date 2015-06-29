#include "custom-list.h"
#include <stdlib.h>
 
void
fill_model (CustomList *customlist)
{
  const gchar  *firstnames[] = { "Joe", "Jane", "William", "Hannibal", "Timothy", "Gargamel", NULL } ;
  const gchar  *surnames[]   = { "Grokowich", "Twitch", "Borheimer", "Bork", NULL } ;
  const gchar **fname, **sname;
 
  for (sname = surnames;  *sname != NULL;  sname++)
  {
    for (fname = firstnames;  *fname != NULL;  fname++)
    {
      gchar *name = g_strdup_printf ("%s %s", *fname, *sname);
 
      custom_list_append_record (customlist, name, 1900 + (guint) (103.0*rand()/(RAND_MAX+1900.0)));
 
      g_free(name);
    }
  }
}
 
GtkWidget *
create_view_and_model (void)
{
  GtkTreeViewColumn   *col;
  GtkCellRenderer     *renderer;
  CustomList          *customlist;
  GtkWidget           *view;
 
  customlist = custom_list_new();
  fill_model(customlist);
 
  view = gtk_tree_view_new_with_model(GTK_TREE_MODEL(customlist));
 
  g_object_unref(customlist); /* destroy store automatically with view */
 
  renderer = gtk_cell_renderer_text_new();
  col = gtk_tree_view_column_new();
 
  gtk_tree_view_column_pack_start (col, renderer, TRUE);
  gtk_tree_view_column_add_attribute (col, renderer, "text", CUSTOM_LIST_COL_NAME);
  gtk_tree_view_column_set_title (col, "Name");
  gtk_tree_view_append_column(GTK_TREE_VIEW(view),col);
 
  renderer = gtk_cell_renderer_text_new();
  col = gtk_tree_view_column_new();
  gtk_tree_view_column_pack_start (col, renderer, TRUE);
  gtk_tree_view_column_add_attribute (col, renderer, "text", CUSTOM_LIST_COL_YEAR_BORN);
  gtk_tree_view_column_set_title (col, "Year Born");
  gtk_tree_view_append_column(GTK_TREE_VIEW(view),col);
 
  return view;
}
 
int
main (int argc, char **argv)
{
  GtkWidget *window, *view, *scrollwin;
 
  gtk_init(&argc,&argv);
 
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_default_size (GTK_WINDOW(window), 200, 400);
  g_signal_connect(window, "delete_event", gtk_main_quit, NULL);
 
  scrollwin = gtk_scrolled_window_new(NULL,NULL);
 
  view = create_view_and_model();
 
  gtk_container_add(GTK_CONTAINER(scrollwin), view);
  gtk_container_add(GTK_CONTAINER(window), scrollwin);
 
  gtk_widget_show_all(window);
 
  gtk_main();
 
  return 0;
}
