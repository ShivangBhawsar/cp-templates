struct measureTime
{
    std::chrono::high_resolution_clock::time_point start_time, end_time;
    measureTime()
    {
        start_time = std::chrono::high_resolution_clock::now();
    }
    ~measureTime()
    {
        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
        std::cout << "Execution Time: " << duration.count() << " microseconds\n";
    }
};
// {
//      measureTime();
//      // ...code
// }