//
// Created by lugt on 2019/5/5.
//

#ifndef GRAPH_GRAPH_UTIL_H
#define GRAPH_GRAPH_UTIL_H

EXTERN INT *New_connections(INT vex_count);

EXTERN INT *Conn_position(INT *conn, INT size, INT lval, INT rval);

EXTERN void Set_connections(INT *conn, INT size, INT lval, INT rval, INT is_connect);

EXTERN BOOL Is_connected(INT *conn, INT size, INT lval, INT rval);

EXTERN INT Get_connected(INT *conn, INT size, INT lval, INT rval);

EXTERN void Print_conn(INT *conn, INT size);

#endif //GRAPH_GRAPH_UTIL_H
