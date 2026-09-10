def remove_disallowed_items(cart: list, dynamic_banned_words: list) -> list:
    # BUG: Iterating directly over a list while removing elements from it
    # skips the immediate next element because the underlying indices shift.
    for item in cart:
        if item in dynamic_banned_words:
            cart.remove(item)
    return cart
