/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:58:03 by bede-car          #+#    #+#             */
/*   Updated: 2022/11/07 21:44:50 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct s_person
{
    char    *name;
    int     age;
} t_human;

void init_person(t_human human)
{
    human.age = 30;
    human.name = "Beatriz";
}

int main(void)
{
    t_human Lux;
    printf("%d %s\n", Lux.age, Lux.name);
    init_person(&s_person);
    printf("%d %s\n", Lux.age, Lux.name);
}
