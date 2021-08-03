-- 游戏玩法分析1
select player_id, min(event_date) as first_login
from Activity
Group by player_id