#include <benchmark/benchmark.h>

#include <dummy.h>

using namespace dummy;

static void DummyBenchmark(benchmark::State &state) {
    Dummy dummy(4);
    for (auto _ : state) {
        benchmark::DoNotOptimize(dummy.GetDummy());
    }
    state.SetComplexityN(state.range(0));
    state.SetItemsProcessed(state.iterations());
}

BENCHMARK(DummyBenchmark)
    ->Repetitions(4)
    ->Range(1 << 4, 1 << 20)
    ->RangeMultiplier(2)
    ->Unit(benchmark::kNanosecond)
    ->ReportAggregatesOnly(true)
    ->Complexity(benchmark::o1);

BENCHMARK_MAIN();