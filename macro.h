/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:55:06 by alajara-          #+#    #+#             */
/*   Updated: 2023/06/08 19:54:39 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H
# define MACRO_H

// SETTINGS

# define WIN_H 500
# define WIN_W 500

# define DEF_ITER 70

// EVENTS

# define N_PALETTES 5
# define KEYPRESS 02
# define MOTIONNOTIFY 06
# define BUTTONPRESS 04
# define DESTROYNOTIFY 17

// Keyboard LETTERS

# define KEY_A 0
# define KEY_B 11
# define KEY_C 8
# define KEY_D 2
# define KEY_E 14
# define KEY_F 3
# define KEY_G 5
# define KEY_H 4
# define KEY_I 34
# define KEY_J 38
# define KEY_K 40
# define KEY_L 37
# define KEY_M 46
# define KEY_N 45
# define KEY_O 31
# define KEY_P 35
# define KEY_Q 12
# define KEY_R 15
# define KEY_S 1
# define KEY_T 17
# define KEY_U 32
# define KEY_V 9
# define KEY_W 13
# define KEY_X 7
# define KEY_Y 16
# define KEY_Z 6

// Keyboard ARROWS

# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_UP 126
# define KEY_DOWN 125

// Keyboard NUMPAD

# define KEY_DIV 75
# define KEY_MUL 67
# define KEY_MIN 78
# define KEY_PLU 69
# define KEY_1 83
# define KEY_2 84
# define KEY_3 85
# define KEY_4 86
# define KEY_5 87
# define KEY_6 88
# define KEY_7 89
# define KEY_8 91
# define KEY_9 92

// Keyboard MISC

# define KEY_SPC 49
# define KEY_ESC 53
# define KEY_TAB 48
# define KEY_CTR 256 //stop mouse
# define KEY_CMD 259

// Mouse

# define M_L_BUTT 1      // Left mouse button
# define M_R_BUTT 2     // Right mouse button
# define M_MID_BUTT 3    // Middle mouse button
# define SCRL_U 4        // Mouse scroll up (Zoom in)
# define SCRL_D 5      // Mouse scroll down (Zoom out)

// Colors

# define RED 16711680
# define GREEN 65280
# define BLUE 255
# define WHITE 16777215
# define BLACK 0
# define GRAY 7829367
# define PINK 16761035

#endif