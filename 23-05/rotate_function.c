/*
** EPITECH PROJECT, 2021
** rotates function
** File description:
** rotate function
*/

int calc_function(int *nums, int numSize)
{
    int i = 0;
    int value = 0;

    while (i < numSize) {
        value += i * nums[i];
        i++;
    }
    return (value);
}

void move_nums(int *nums, int numsSize)
{
    int i = numsSize - 1;
    int temp = nums[numsSize - 1];

    while(i > 0) {
        nums[i] = nums[i - 1];
        i--;
    }
    nums[0] = temp;
}

int maxRotateFunction(int *nums, int numsSize)
{
    int value = calc_function(nums, numsSize);
    int i = 0;

    while (i < numsSize) {
        move_nums(nums, numsSize);
        if (calc_function(nums, numsSize) > value)
            value = calc_function(nums, numsSize);
        i++;
    }
    return (value);
}