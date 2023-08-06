class Solution {
public:
    int N_SONGS, GOAL_SONGS, K;
    const int MOD = 1e9+7;
    long long memo[101][101];
    long long solve(int songs_count, int unique_songs_count){
        // if the total songs count is reached goal songs playlist and also all the unique songs are played the return 1 playlist else return 0
        if(songs_count == GOAL_SONGS){
            if(unique_songs_count==N_SONGS){
                return 1;
            }else {
                return 0;
            }
            
        } 
        if(memo[songs_count][unique_songs_count] != -1){
            return memo[songs_count][unique_songs_count];
        }
        long long answer = 0;
        // 1 option we have to play unique song
        if(unique_songs_count < N_SONGS){
            answer += (N_SONGS-unique_songs_count) * solve(songs_count+1,unique_songs_count+1);
        }
        // 2 options we have to replay prev song
        if(unique_songs_count > K){
            answer +=  (unique_songs_count - K)* solve(songs_count+1,unique_songs_count);
        }
        return memo[songs_count][unique_songs_count] = answer%MOD;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        N_SONGS = n;
        GOAL_SONGS = goal;
        K = k;
        memset(memo,-1,sizeof(memo));
        return solve(0,0);
    }
};