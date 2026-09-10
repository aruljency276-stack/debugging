import asyncio

class SessionCacheManager:
    def __init__(self):
        self._cache = {}

    async def register_session(self, user_id: str, dynamic_token: str) -> bool:
        # BUG: A tiny non-atomic async yield context switch point
        # allows duplicate initialization pipelines to execute simultaneously.
        if user_id not in self._cache:
            await asyncio.sleep(0.001)  # Simulates disk access latency
            self._cache[user_id] = []
            
        self._cache[user_id].append(dynamic_token)
        return True

    def get_user_tokens(self, user_id: str) -> list:
        return self._cache.get(user_id, [])
