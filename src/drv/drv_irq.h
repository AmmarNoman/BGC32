///////////////////////////////////////////////////////////////////////////////

#pragma once

///////////////////////////////////////////////////////////////////////////////

extern volatile int __irq_nesting_counter;

///////////////////////////////////////////////////////////////////////////////

__attribute__((always_inline)) __STATIC_INLINE void __disable_irq_nested(void)
{
    __disable_irq();
    __irq_nesting_counter++;
}

///////////////////////////////////////////////////////////////////////////////

__attribute__((always_inline)) __STATIC_INLINE void __enable_irq_nested(void)
{
    if (--__irq_nesting_counter == 0)
    {
        __enable_irq();
    }
}

///////////////////////////////////////////////////////////////////////////////

