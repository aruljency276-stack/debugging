import sys
from cart import remove_disallowed_items

def run_test():
    student_cart = ["apple", "vape", "tobacco", "banana"]
    banned = ["vape", "tobacco"]
    
    # If the bug triggers, "tobacco" will be skipped and left in the cart
    result = remove_disallowed_items(student_cart, banned)
    print(f"[LOG] Cleaned Cart: {result}")
    
    assert "tobacco" not in result, "❌ TEST FAILED: Consecutive banned items skipped!"
    assert len(result) == 2, f"❌ TEST FAILED: Expected 2 items, got {len(result)}"
    print("✅ TEST PASSED: List mutation safely handled.")

if __name__ == "__main__":
    run_test()
