const path = require('path');

module.exports = {
  // entry: './src/code.ts', // cold observable
  // entry: './src/code_hot_observable.ts',
  // entry: './src/code_subject.ts',
  // entry: './src/code_replay_subject.ts',
  // entry: './src/code_async_subject.ts',
  // entry: './src/code_operator_pluck_example.ts',
  entry: './src/code_obs_subj_op_example.ts',
  devtool: 'inline-source-map',
  module: {
    rules: [
      {
        test: /\.tsx?$/,
        use: 'ts-loader',
        exclude: /node_modules/
      }
    ]
  },
  resolve: {
    extensions: [ '.ts', '.js', '.tsx' ]
  },
  output: {
    filename: 'bundle.js',
    path: path.resolve(__dirname, 'dist')
  }
};