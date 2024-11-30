/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:38:40 by tomlimon          #+#    #+#             */
/*   Updated: 2024/11/30 15:56:16 by tomlimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int word_count(const char *str, char delimiter)
{
    int count = 0;
    int in_word = 0;

    while (*str)
    {
        if (*str != delimiter && !in_word)
        {
            in_word = 1;
            count++;
        }
        else if (*str == delimiter)
        {
            in_word = 0;
        }
        str++;
    }
    return (count);
}

static char *word_extract(const char *str, char delimiter)
{
    int len = 0;
    char *word;

    while (str[len] && str[len] != delimiter)
        len++;
    word = (char *)malloc(sizeof(char) * (len + 1));
    if (!word)
        return (NULL);
    for (int i = 0; i < len; i++)
        word[i] = str[i];
    word[len] = '\0';
    return (word);
}

char **ft_split(const char *str, char delimiter)
{
    int i = 0;
    int words;
    char **result;

    if (!str)
        return (NULL);
    words = word_count(str, delimiter);
    result = (char **)malloc(sizeof(char *) * (words + 1));
    if (!result)
        return (NULL);
    while (*str)
    {
        if (*str != delimiter)
        {
            result[i] = word_extract(str, delimiter);
            if (!result[i++])
            {
                while (--i >= 0)
                    free(result[i]);
                free(result);
                return (NULL);
            }
            while (*str && *str != delimiter)
                str++;
        }
        else
        {
            str++;
        }
    }
    result[i] = NULL;
    return (result);
}

void handle_single_argument(char *arg, t_stack **a)
{
    char **split_args;
    int count;
    int i;

    split_args = ft_split(arg, ' ');
    if (!split_args)
    {
        write(2, "Error\n", 6);
        exit(EXIT_FAILURE);
    }

    count = 0;
    while (split_args[count])
        count++;

    *a = (t_stack *)malloc(sizeof(t_stack));
    if (!*a)
    {
        write(2, "Error\n", 6);
        free_split(split_args);
        exit(EXIT_FAILURE);
    }

    (*a)->data = (int *)malloc(sizeof(int) * count);
    if (!(*a)->data)
    {
        free(*a);
        write(2, "Error\n", 6);
        free_split(split_args);
        exit(EXIT_FAILURE);
    }

    (*a)->size = count;
    for (i = 0; i < count; i++)
    {
        (*a)->data[i] = ft_atoi(split_args[i]);
    }

    free_split(split_args);
}

