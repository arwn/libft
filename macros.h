/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 14:11:27 by awindham          #+#    #+#             */
/*   Updated: 2019/04/13 15:25:06 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# define VAR int

# define LOCAL	static
# define PROC	extern
# define TYPE	typedef
# define STRUCT	TYPE struct
# define UNION	TYPE union
# define REG	register
# define INT    int
# define CHAR   char

# define IF	if(
# define THEN	){
# define ELSE	} else {
# define ELIF	} else if (
# define FI	;}

# define BEGIN	{
# define END	}
# define SWITCH	switch(
# define IN	){
# define ENDSW	}
# define FOR	for(
# define WHILE	while(
# define DO	){
# define OD	;}
# define REP	do{
# define PER	}while(
# define DONE	);
# define LOOP	while(1){
# define POOL	}

# define INC ++;
# define IS =
# define EQ ==

# define SKIP    ;
# define DIV /
# define REM	%
# define NEQ	^
# define ANDF	&&
# define ORF	||

# define TRUE	(-1)
# define FALSE	0
# define LOBYTE	0377
# define STRIP	0177
# define QUOTE	0200

# define NL	'\n'
# define SP	' '
# define LQ	'`'
# define RQ	'\''
# define MINUS	'-'
# define COLON	':'

# define MAX(a,b)	((a)>(b)?(a):(b))

#endif
