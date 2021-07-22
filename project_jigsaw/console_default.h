/**
 * Title: Console Default
 * Feature: Console basic functions
 * File: console_default.h
 * Author: Unchun Yang
 */

#pragma once

#include <stdbool.h>

// Get and set cursor's position.
void gotoxy(short x, short y);
int wherex();
int wherey();

// Console appearance functions
void set_output_color(int color);
void set_cursor_type(bool bShow);
void resize_console(short nWidth, short nHeight);