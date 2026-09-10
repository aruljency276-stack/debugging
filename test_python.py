import asyncio
import sys
from solution import SessionCacheManager

async def run_grading_test():
    manager = SessionCacheManager()
    user_id = "student_user_404"
    
    # Simulate a sudden high-concurrency burst of requests for the exact same user
    tokens_to_inject = [f"Token_Hex_{i}" for i in range(10)]
    tasks = [manager.register_session(user_id, token) for token in tokens_to_inject]
    
    await asyncio.gather(*tasks)
    
    tokens_stored = manager.get_user_tokens(user_id)
    print(f"[TEST LOG] Stored Tokens: {tokens_stored}")

    # TEST ASSERTION
    # If the bug is active, the list resets mid-flight, losing the early tokens.
    if len(tokens_stored) != 10:
        print(f"❌ TEST FAILED: Concurrency Race Condition! Lost {10 - len(tokens_stored)} items.")
        sys.exit(1)
        
    print("✅ TEST PASSED: State machine safely encapsulated across async barriers.")
    sys.exit(0)

if __name__ == "__main__":
    asyncio.run(run_grading_test())
